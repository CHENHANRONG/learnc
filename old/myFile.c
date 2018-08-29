#include<stdio.h>

void readFile0(char *filePath){
    FILE *fp = fopen(filePath, "r");
    int ch;
    while((ch=getc(fp))!=EOF){
        putchar(ch);
    }
    fclose(fp);
}
