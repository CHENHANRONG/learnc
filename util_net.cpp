

//
//  util_net.cpp
//  cpp

// reference : https://curl.haxx.se/libcurl/c/multithread.html
//
//  Created by 陈含荣 on 2018/5/31.
//  Copyright © 2018年 陈含荣. All rights reserved.
//

#include "util_net.hpp"

#include <stdlib.h>
#include <string.h>

#define NUM_THREAD 5

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



int get_stock_data_from_sina(char* base_url, unsigned int stock_list_len, unsigned short stock_code_len){
   
    const char *stockcodes[stock_list_len];
    int i;
    for(i=0;i<stock_list_len;i++){
        stockcodes[i]= (char*)malloc(sizeof(char)*stock_code_len);
        stockcodes[i] = "60000"+i;
    }
}

int main(int argc, char **argv)
{
    const unsigned int NUM_STOCKCODES = 10;
    const unsigned short LEN_STOCKCODE = 7;  //stock code len is 6 and end with \0
}
/*
 List of URLs to fetch.
 
 If you intend to use a SSL-based protocol here you might need to setup TLS
 library mutex callbacks as described here:
 
 https://curl.haxx.se/libcurl/c/threadsafe.html
 
 */
const char * const urls[NUMT]= {
    "https://curl.haxx.se/",
    "ftp://cool.haxx.se/",
    "http://www.contactor.se/",
    "www.haxx.se"
};

