//
//  util_net.cpp
//  cpp
//
//  Created by 陈含荣 on 2018/5/31.
//  Copyright © 2018年 陈含荣. All rights reserved.
//

#include "util_net.hpp"

#include <stdlib.h>
#include <string>
#include <ctime>

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
        printf("input stock code is NULL");
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

