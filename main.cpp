//
//  main.c
//  cpp
//
//  Created by 陈含荣 on 2018/5/6.
//  Copyright © 2018年 陈含荣. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define min(a, b)    (a) < (b) ? a : b
#define array_length(arr) (sizeof(arr) == 0 ? 0 : sizeof(arr)/sizeof((arr)[0]))

void print_bytes(const void *object, size_t size);
void hexDump(char *desc, void *addr, int len);
void print_array(float[],int);
void print_array1(int array[], int begin, int end);
//void bubbleSort1(float[],int);
//void bubbleSort2(float[],int);
//void readFile(char *filePath);
int* generate_int_array(int *ia, int size);
void swap(int v[], int i, int j);
// void qsort0(int v[], int left, int right);


int main(void){
    int ia[] = {11,0,7,1,10,8,6,9,12,2,3,4};

   
//    puts("stop");
}

//==========================================================

//==========================================================

//==========================================================

//==========================================================

//==========================================================

//==========================================================
//    qsort0(ia,0,array_length(ia));
//    print_array1(ia, 0, array_length(ia));
//==========================================================
//    Size of structures
//struct{
//    //smaller type auto padding to same as longest type in struct
//    char c;
//    int i;
//    long l;
//    double d
//}x;
//printf("size=%d\n", sizeof(x));

//==========================================================
//    int intArrary[] = {8,5,0,1,2,3,4,6,9,11,10};
//    int *pIA = intArrary;
//
//    void shit_element(unsigned i){
//        int ivalue;
//
//        for(ivalue = *(pIA+i); i && *(pIA+i-1) > ivalue; i--)
//            *(pIA+i) = *(pIA+i-1);  //move bigger value to later one
//        *(pIA+i) = ivalue;  // move smaller value to
//    }
//
//    void insertion_sort (void) {
//        unsigned int i;
//        unsigned int len = array_length(intArrary);
//        for (i = 1; i < len; i++){
//            if (*(pIA+i) <  *(pIA+i-1))
//                shit_element(i);
//        }
//    }

//==========================================================
//    array and pointer
//    printf("*(pIA+3) = %d\n", *(pIA+3));
//    pointer conversion
//    char *pCA = (char*)pIA;
//    printf("*(pCA+3) = %d\n", *(pCA+3));
//    printf("*(pCA+4) = %d\n", *(pCA+4));
//    printf("*(pCA+5) = %d\n", *(pCA+4));
//    printf("*(pCA+3*sizeof(int) = %d\n", *(pCA+3*sizeof(int)));
//==========================================================

//    void readFile(char *filePath){
//        FILE *fp = fopen(filePath, "r");
//        int ch;
//        while((ch=getc(fp))!=EOF){
//            putchar(ch);
//        }
//        fclose(fp);
//    }

    
//==========================================================
//    union xunion{
//        int num;
//        char c;
//    };
//
//    union xunion *x = malloc(sizeof(union xunion));
//    x->num = 1024;
//    print_bytes (x, sizeof(union xunion));
//
//
//    x->c = 'c';
//    print_bytes (x, sizeof(union xunion));
//
//    printf("size of union = %lu\n", sizeof(union xunion));
//    printf("xunion's num=%d\n", x->num);
//    printf("xunion's c=%c\n",x->c);
//==========================================================
//    int static_arr[20];
//    int *dynamic_arr = malloc(20*sizeof(int));
//    *dynamic_arr = 10 ;
//    dynamic_arr[1] = 1;
//    dynamic_arr[2] = 2;
//    *(dynamic_arr+3) = 3;
//
//    printf("sizeof(static_arr) = %lu\n", sizeof(static_arr));
//    printf("sizeof(dynamic_arr) = %lu\n", sizeof(dynamic_arr));
//    printf("dynamic_arr[3] = %d\n", dynamic_arr[3]);


    
//    int len = 10;
//    float testnums[10];
//    for(int i = 0; i < len; i++ ) {
//        testnums[i] = rand();
//    }
//
//    bubbleSort1(testnums, 10);
//    bubbleSort2(testnums,10);
    


/*
 char color;
 //    color = getchar();
 scanf("%c", &color);
 //    printf("color value = %c\n", color);
 switch(color){
 case 'r':
 puts("this is r");
 break;
 case 'g':
 puts("this is g\n");
 case 'b':
 puts("this is b\n");
 break;
 default:
 puts("no such option");
 }
 */

/*generate random number*/
int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;
    
    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }
    
    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

int* generate_int_array(int *ia, int size){
    srand((unsigned int)time(NULL));
    int i=0;
    for(i=0;i<size;i++)
        ia[i] = rand()%100+1;
    
    return ia;
}


void print_bytes(const void *object, size_t size)
{
    // This is for C++; in C just drop the static_cast<>() and assign.
//    const unsigned char * const bytes = static_cast<const unsigned char *>(object);
    const unsigned char * const bytes = object;

    size_t i;
    
    printf("[ ");
    for(i = 0; i < size; i++)
    {
        printf("%02x ", bytes[i]);
    }
    printf("]\n");
}

void hexDump (char *desc, void *addr, int len) {
    int i;
    unsigned char buff[17];       // stores the ASCII data
    unsigned char *pc = addr;     // cast to make the code cleaner.
    
    // Output description if given.
    
    if (desc != NULL)
        printf ("%s:\n", desc);
    
    // Process every byte in the data.
    
    for (i = 0; i < len; i++) {
        // Multiple of 16 means new line (with line offset).
        
        if ((i % 16) == 0) {
            // Just don't print ASCII for the zeroth line.
            
            if (i != 0)
                printf ("  %s\n", buff);
            
            // Output the offset.
            
            printf ("  %04x ", i);
        }
        
        // Now the hex code for the specific character.
        
        printf (" %02x", pc[i]);
        
        // And store a printable ASCII character for later.
        
        if ((pc[i] < 0x20) || (pc[i] > 0x7e))
            buff[i % 16] = '.';
        else
            buff[i % 16] = pc[i];
        buff[(i % 16) + 1] = '\0';
    }
    
    // Pad out last line if not exactly 16 characters.
    
    while ((i % 16) != 0) {
        printf ("   ");
        i++;
    }
    
    // And print the final ASCII bit.
    
    printf ("  %s\n", buff);
}

void print_array(float array[], int len){
    puts("===========start to print array:");
    for(int i = 0; i < len; i++ ) {
        printf("%dth element value = %f\n", i, array[i]);
    }
    puts("===========end to print array.");
}

void print_array1(int array[], int begin, int end){
    puts("===========start to print array:");
    for(int i = begin; i < end; i++ ) {
        printf("%dth element value = %d\n", i, array[i]);
    }
    puts("===========end to print array.");
}



void readFile(char *filePath){
    FILE *fp = fopen(filePath, "r");
    int ch;
    while((ch=getc(fp))!=EOF){
        putchar(ch);
    }
    fclose(fp);
}


//unsigned int Fibonacci(unsigned int n){
//    if(n<2){
//        return n;
//    }else{
//        return Fibonacci(n-1)+Fibonacci(n-2);
//    }
//}


void bubbleSort1(float nums[], int len){
    float temp;
    int swap_flag = FALSE;
    int loop_counter = 0;
    do{
        swap_flag = FALSE;
        for(int i=1; i<len; i++){
            if(nums[i]<nums[i-1]){
                temp = nums[i-1];
                nums[i-1] = nums[i];
                nums[i] = temp;
                swap_flag = TRUE;
            }
            loop_counter++;
        }
    }while(swap_flag);
    
    printf("loop_counter = %d\n", loop_counter);
    print_array(nums,len);
}



void bubbleSort2(float nums[], int len){
    float temp;
    int loop_counter = 0;
    int i,j;
    
    for(i=0;i<len;i++){
        for(j=i+1;j<len;j++){
            if(nums[i]>nums[j]){
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            loop_counter++;
        }
    }
    printf("loop_counter = %d\n", loop_counter);
    print_array(nums,len);
}




void swap(int v[], int i, int j){
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

//    void swap(int v[], int i, int j);
/* qsort: sort v[left]...v[right] in increaseing order */
void qsort0(int v[], int left, int right){
    int i, last;
    
    // do nothing if array contains fewer than two elements
    if(left >= right)
        return;
//    print_array1(v, left, right);
    swap(v, left, (left+right)/2);  //move partition elem to v[0]
    print_array1(v, left, right);
    last = left;
    puts("started to swapped>>>>>>>>>>>");
    for(i = left+1; i <= right; i++)  //partition
        if(v[i] < v[left]){
//            printf("i=%d\t, last=%d\n",i, last);
            swap(v,++last,i);
            print_array1(v, left, right);
            puts("swapped>>>>>>>>>>>");

        }

    
    swap(v,left, last);  //restore partition elem
//    print_array1(v, left, right);
    qsort0(v, left, last-1);
    qsort0(v, last+1, right);
}
    
                    

