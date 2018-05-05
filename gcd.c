/*====================================
gcd.c
greatest common divisor (gcd)
 
//=======================================
//  learnc
//
//  Created by hanrong chen on 5/5/18.
//  Copyright © 2018 hanrong chen. All rights reserved.
*/

#include <stdio.h>

#define min(a,b) ((a)<(b)?(a):(b))

/*
 最大公约数
 */
int gcd0(int a, int b){
    int i, ret = 1, minval = min(a,b);
    for(i=2;i<=minval;i++){
        if(a%i)
            continue;
        if(b%i == 0){
            ret = i;
        }
    }
    
    return ret;
}

/*Euclid's algorithm*/
int gcd1(int a, int b){
    int loop_cnt = 0;
    while(b){  //if a<b, performs swap
        int temp = b;
        b = a%b;
        a = temp;
        loop_cnt++;
    }
    
    printf("loop cnt = %d\n", loop_cnt);
    
    return a;
}

int main(int argc, char** argv){
    int a = 60;
    int b = 11;
    printf("gcd0(a,b) = %d\n", gcd0(a,b));
    printf("gcd1(a,b) = %d\n", gcd1(a,b));
}
