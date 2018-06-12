//
//  util_net.cpp
//  cpp
//
//  Created by 陈含荣 on 2018/5/31.
//  Copyright © 2018年 陈含荣. All rights reserved.
//

#include "util_net.hpp"

#include <stdlib.h>
#include <cstring>
#include <ctime>
#include <curl/curl.h>


#define NUM_THREAD 5


/* =============================================
 *
 * =============================================*/
#define STOCKCODE_LEN 6



void get_today_str(char *day_str){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[9];
    
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%Y%m%d",timeinfo);
    buffer[8]='\0';
//    strftime(buffer,sizeof(buffer),"%d-%m-%Y %I:%M:%S",timeinfo);
//    std::string str(buffer);
    strncpy(day_str, buffer, 8);
//    std::cout << str;
    printf("date string = %s\n",day_str);
//    return str.c_str();
}
char * get_stock_data_from_163(const char *stockcode){
    //    symbol = '0%s' % code if code[:1] in ['5', '6', '9'] else '1%s' % code
    if(stockcode == NULL){
        fprintf(stderr, "input stock code is NULL");
    }else{
        printf("input stock code is %s", stockcode);
    }
    
    char symbol[8];
    if(strncmp(stockcode, "5", 1) == 0
       || strncmp(stockcode, "6", 1) == 0
       || strncmp(stockcode, "9", 1) == 0){
        snprintf(symbol, 8, "0%s", stockcode);
    }else{
        snprintf(symbol, 8, "1%s", stockcode);
    }
    
    //snprintf(stockcodes[i],stock_code_len, "%d", 60000+i);
    const char* WEB_SERVICE_163 = "http://quotes.money.163.com/service/";
//    end = '%s' % end if end is not None else date.today().strftime("%Y%m%d")
    char end_day_str[9];
    get_today_str(end_day_str);
    printf("date string = %s", end_day_str);
//    char CNA_DAY_TRADE_URL[500];
    char *CNA_DAY_TRADE_URL = (char*)malloc(sizeof(char)*500);
    snprintf(CNA_DAY_TRADE_URL, 500, "%schddata.html?code=%s&start=19800101&end=%s&fields=TCLOSE;HIGH;LOW;TOPEN;LCLOSE;CHG;PCHG;TURNOVER;VOTURNOVER;VATURNOVER;TCAP;MCAP"
             , WEB_SERVICE_163, symbol, end_day_str);
    
    return CNA_DAY_TRADE_URL;
}

/* the function to invoke as the data recieved */
size_t static write_callback_func(void *buffer,
                                  size_t size,
                                  size_t nmemb,
                                  void *userp)
{
    printf("\n\nIn write_callback_func()...\n");
    int bufferlen = strlen(buffer);
    printf("In write_callback_func(): strlen(buffer) = [%d]\n", bufferlen);
    printf("In write_callback_func(): buffer = [%s]\n", buffer);
    char **response_ptr = (char**)userp;
    printf("In write_callback_func(): About to call strndup()...\n");
    /* assuming the response is a string */
    //*response_ptr = strndup(buffer, (size_t)(size *nmemb));
    apr_cpystrn((const char *)userp, buffer, bufferlen);
    printf("In write_callback_func(): Finished setting *response_ptr, returning...\n");
} // end write_callback_func()

static void *pull_one_url(void *url)
{
    CURL *curl;
    CURLcode res;
    char errbuf[CURL_ERROR_SIZE];
    const char * response;

    
    curl = curl_easy_init();
    if(curl) {

        curl_easy_setopt(curl, CURLOPT_URL, url);
        /* setting a callback function to return the data
         https://curl.haxx.se/libcurl/c/getinmemory.html
         https://stackoverflow.com/questions/2329571/c-libcurl-get-output-into-a-string
         */
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback_func);
        /* passing the pointer to the response as the callback parameter */
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        printf("In callCurl(): Returned from calling curl_easy_setopt()...\n");
        /* provide a buffer to store errors in */
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
        

        int i=0;
        while(i<5){
            
            /* set the error buffer as empty before performing a request */
            errbuf[0] = 0;
            // perform
            res = curl_easy_perform(curl); /* ignores error */
            printf("\n\n\nres=[%s]\n", res);
            
            
            /* if the request did not complete correctly, show the error
             information. if no detailed error information was written to errbuf
             show the more generic information from curl_easy_strerror instead.
             */
            if(CURLE_OK != res) {
                size_t len = strlen(errbuf);
                fprintf(stderr, "\nlibcurl: (%d) ", res);
                if(len)
                    fprintf(stderr, "%s%s", errbuf,
                            ((errbuf[len - 1] != '\n') ? "\n" : ""));
                else
                    fprintf(stderr, "%s\n", curl_easy_strerror(res));
            }else{
                /* get response code */
                int response_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                printf("We received response code = %d\n", response_code);

                char *ct;
                /* ask for the content-type */
                res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
                if(ct){
                    printf("We received Content-Type: %s\n", ct);
                }else{
                    fprintf(stderr, "curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct) returns NULL");
                }
                
                //curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &size);
                double size;
                curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &size);
                
                break;
            }
/*
            if(response_code>199 && response_code<300){   //Things are OK
                printf("http response code = %d", response_code);
                break;
            }else if( i++ == 5 && (response_code>399 || response_code<200)){
                //4xx - Failed because of a client problem
                //5xx - Failed because of a server problem
                fprintf(stderr, "http response code = %d", response_code);
            } */
        }


        curl_easy_cleanup(curl);
    }else{
        fprintf(stderr, "curl_easy_init() returns NULL");
    }
    
    return NULL;
}

/*
char ** get_list_of_stock_data_from_163(char *stock_codes[], unsigned int number_of_stocks){
    //char **stockcodes= (char**)malloc(sizeof(char*)*stock_list_len);int i;
    int i;
    for(i=0;i<stock_list_len;i++){
        //    char * istock = (char*)malloc(sizeof(char)*(STOCKCODE_LEN+1));
        
    }
    
}
*/
int main(int argc, char **argv)
{
//    const unsigned int NUM_STOCKCODES = 10;
//    const unsigned short LEN_STOCKCODE = 7;  //stock code len is 6 and end with \0
//    const char* WEB_SERVICE_163 = "http://quotes.money.163.com/service/";
    get_stock_data_from_163("600036");
    return EXIT_SUCCESS;
}



/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int i, j;
    char c;
    
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


/*
 List of URLs to fetch.
 
 If you intend to use a SSL-based protocol here you might need to setup TLS
 library mutex callbacks as described here:
 
 https://curl.haxx.se/libcurl/c/threadsafe.html
 
 */
//const char * const urls[NUMT]= {
//    "https://curl.haxx.se/",
//    "ftp://cool.haxx.se/",
//    "http://www.contactor.se/",
//    "www.haxx.se"
//};

