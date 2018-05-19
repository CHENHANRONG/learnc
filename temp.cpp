//
//  temp.cpp
//  cpp
//
//  Created by 陈含荣 on 2018/5/19.
//  Copyright © 2018年 陈含荣. All rights reserved.
//

//#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <typeinfo>
#include <cstring>
#include <cstdarg>
#include <ctime>

#include "game.hpp"

#define MAX 1000
#define TRUE 1
#define FALSE 0
#define min(a, b)    (a) < (b) ? a : b
#define array_length(arr) (sizeof(arr) == 0 ? 0 : sizeof(arr)/sizeof((arr)[0]))


int strcmp_wrapper(void *pa, void *pb){
    return strcmp((const char*)pa, (const char*)pb);
}



void print_bytes(const void *object, size_t size);
void hexDump(char *desc, void *addr, int len);
void print_array(int[],int);
void print_array1(int array[], int begin, int end);
int* linear_search(int val, int *arr, size_t n);
void shift_element (unsigned int i , int arr[]);
void insertion_sort (int arr[], size_t len);


//address of fun and local paramters
void testfunloc(int x){
    int y = 0;
    x = 1;
    printf("address of x=%p\n", &x);
    printf("address of y=%p\n", &y);
}

//printf("address of main=%p\n", &main);
//int z = 3;
//printf("address of z=%p\n", &z);
//testfunloc(z);
//printf("address of fun=%p\n", &testfunloc);

//=================================

struct node{
    int data;
    struct node* next;
};

struct node* head;

void apply(struct node *phead, void (*fp)(void *, void *), void *arg){
    struct node *p = phead;
    while(p!=NULL){
        fp(p, arg);
        p = p->next;
    }
}

enum TYPE{SQUARE, RECT, CIRCLE, POLYGON};
struct shape{
    float params[MAX];
    enum TYPE type;
};

void draw_square(struct shape* ps){
    
}
void draw_rec(struct shape* ps){
    
}
void draw_circle(struct shape* ps){
    
}
void draw_poly(struct shape* ps){
    
}
void (*fp[4])(struct shape* ps) = {&draw_square, &draw_rec, &draw_circle, &draw_poly};
void draw(struct shape* ps){
    (*fp[ps->type]) ( ps ) ;
    //    switch(ps->type){
    //        case SQUARE:
    //            fp[0](ps);
    //            break;
    //        case RECT:
    //            fp[1](ps);
    //            break;
    //        case CIRCLE:
    //            fp[2](ps);
    //            break;
    //        case POLYGON:
    //            fp[3](ps);
    //            break;
    //        default:
    //           ;
    //    }
}
//=================================

struct node* new_node(int data){
    struct node* pn=(struct node*)malloc(sizeof(node));
    if(pn!=NULL){
        pn->data = data;
        pn->next = NULL;
    }
    return pn;
}

struct node* add_frond(struct node* head, int data){
    struct node *np = new_node(data);
    if(np == NULL){
        return head;
    }else{
        head->next = np;
        return head;
    }
}
//=================================
/* move previous elements down insertion point reached  */
void shift_element (unsigned int i , int arr[]) {
    int ivalue;
    /* guard against going outside array */
    for (ivalue = arr[i]; i && arr[i-1] > ivalue; i--){
        arr[i] = arr[i-1]; /* move element down */
    }
    arr[ i ] = ivalue ;
}

/*iterate until out−of−order element found; shift the element, and continue iterating */
void insertion_sort (int arr[], size_t len) {
    unsigned int i;
    for (i = 1; i < len; i++){
        if (arr[i] < arr[i-1]){
            shift_element(i, arr);
        }
        print_array(arr, len);
    }
}
//=================================
int *binary_search0(int val, int *arr, unsigned int arr_size){
    unsigned int L=0, R=arr_size, M;
    while(L<R){
        M = (L+R-1)/2;  // find middle
        if(val == arr[M]){
            return arr+M;
        }else if(val<arr[M]){
            R = M;  // val < arr[M]
        }else{
            L = M+1;
        }
    }
    
    return NULL;  // no match
}
//=================================



//double average(const int count, ...)
//{
//    va_list ap;
//    int i;
//    double total = 0.0;
//
//    va_start(ap, count);
//    for(i = 0; i < count; ++i) {
//        total += va_arg(ap, double);
//    }
//    va_end(ap);
//    return total / count;
//}
//
//// works like printf, format plus args
//int message(const char * fmt, ...) {
//    va_list ap;
//    va_start(ap, fmt);
//    int rc = vfprintf(stdout, fmt, ap);
//    puts("");
//    va_end(ap);
//    return rc;
//}
//
//int main( int argc, char ** argv ) {
//    message("This is a message");
//    message("Average: %lf", average(5, 25.0, 35.7, 50.1, 127.6, 75.0));
//    return 0;
//}














/*
 
 //============================================
 
 const char* u8_to_bin(unsigned int x){
 static char s[sizeof(char)+1];
 for(char &c : s)
 c=0;
 char *sp = s;
 for(unsigned char z=128; z>0; z>>=1){
 *(sp++) = ((x&z) == z) ? '1':'0';
 }
 return s;
 }
 
 //============================================
 
 // pass by value
 void func0(int x){
 printf("in func0 x = %d\n", x);
 x = 30;
 }
 
 void fun00(int x){
 printf("in func00 index is %d\n", x);
 }
 void fun01(int x){
 printf("in func01 index is %d\n", x);
 }
 
 // pass by reference
 void func1(int &ix){
 printf("in func1 ix = %d\n", ix);
 ix = 20;
 }
 
 // pass by pointer
 void func2(int *ip){
 printf("ip = %d\n", *ip);
 *ip = 40;
 }
 
 const char * prompt(){
 puts("Choose an option:\n");
 puts("1. Fun00\n");
 puts("2. fun01\n");
 puts(">>>");
 fflush(stdout);
 const int buffsz=16;
 static char resp[buffsz];
 fgets(resp,buffsz, stdin);
 
 return resp;
 }
 
 void (*fp[])(int)={fun00, fun01, NULL};
 
 int jump(const char * rs){
 char code = rs[0];
 if(code == 'q' || code == 'Q') return 0;
 
 //count the length of the fun array
 int len = 0;
 while( fp[len] != NULL){
 len++;
 }
 printf("sizeof(fp) is %lu\n", sizeof(fp));
 printf("sizeof(*fp) is %lu\n", sizeof(*fp));
 printf("length is %lu\n", sizeof(fp)/sizeof(*fp));
 
 int i = (int) code - '0';
 i--;
 if( i < 0 || i > len){
 puts("Invalid choice");
 return 1;
 }else{
 fp[i](i);
 return 1;
 }
 }
 
 void print_bytes(const void *object, size_t size)
 {
 // This is for C++; in C just drop the static_cast<>() and assign.
 const unsigned char * const bytes = static_cast<const unsigned char *>(object);
 size_t i;
 
 printf("[ ");
 for(i = 0; i < size; i++)
 {
 printf("%02x ", bytes[i]);
 }
 printf("]\n");
 }
 
 int main(int argc, const char * argv[]) {
 
 
 int ax[]={1,2,3,4,5,6};
 printf("sizeof(ax) = %lu\n", sizeof(ax));
 //    char str[]={'a','b','c','d','e'};
 char str[]="abcdefgigjk";
 printf("sizeof(str) = %lu\n", sizeof(str));
 printf("strlen(str) = %lu\n", strlen(str));
 
 char *pstr="abced";
 printf("sizeof(pstr) = %lu\n", sizeof(pstr));
 
 
 
 
 
 
 int ix = 100;
 int *p =&ix;
 printf("*p = %d\n", *p);
 printf("sizeof(*p) = %d\n", sizeof(*p));
 printf("sizeof(p) = %d\n", sizeof(p));
 
 
 
 printf("sizeof(char) = %d\n", sizeof(char));
 printf("sizeof(int) = %d\n", sizeof(int));
 printf("sizeof(long) = %d\n", sizeof(long));
 
 printf("sizeof(unsigned int) = %d\n", sizeof(unsigned int));
 printf("sizeof(unsigned long) = %d\n", sizeof(unsigned long));
 
 union{                  //定义一个联合
 int i;
 struct{            //在联合中定义一个结构
 char first;
 char second;
 }half;
 }number;
 print_bytes(&number, sizeof(number));
 printf("sizeof(number) = %d\n", sizeof(number));
 printf("number = %p\n", number);
 number.i=0x4241;         //联合成员赋值
 print_bytes(&number, sizeof(number));
 printf("%c%c\n", number.half.first, number.half.second);
 number.half.first='a';   //联合中结构成员赋值
 number.half.second='b';
 print_bytes(&number, sizeof(number));
 printf("%x\n",number.i);
 
 
 Point p1;
 p1.x = 1;
 p1.y = 0;
 
 Vector v;
 v.x = 2;
 v.y = 3;
 
 Point p2 = p1.AddVector(v);
 printf("p2.x=%f, p2.y=%f\n", p2.x, p2.y);
 
 while(jump(prompt()));
 puts("done\n");
 return 0;
 
 
 
 
 int x = 10;
 
 func0(x);
 printf("after func0 x = %d\n",x);
 
 func1(x);
 printf("after func1 x = %d\n",x);
 
 func2(&x);
 printf("after func2 x = %d\n",x);
 
 
 int y = 10;
 switch (y) {
 case 1:
 puts("one");
 break;
 case 2:
 puts("two");
 case 3:
 puts("three");
 case 4:
 puts("four");
 break;
 case 5:
 puts("five");
 break;
 default:
 puts("default");
 }
 
 
 int ia[10] = {0,1,2,3,4,5,6,7,8,9};
 
 printf("address of ia is %d \n", &ia);
 printf("value of ia is %d \n", ia);
 printf("value of *ia is %d \n", *ia);
 
 
 int x = 10;
 int *ipx = &x;
 printf("x address is %d\n", &x);
 printf("x value is %d\n", x);
 printf("ipx address is %d\n", &ipx);
 printf("ipx value is %d\n", ipx);
 printf("*ipx value is %d\n", *ipx);
 
 
 
 
 
 
 //    std::cout << "Hello, World!\n";
 return 0;
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
    const unsigned char * const bytes = (unsigned char *)object;
    
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
    unsigned char *pc = (unsigned char *)addr;     // cast to make the code cleaner.
    
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

void print_array(int array[], int len){
    puts("===========start to print array:");
    for(int i = 0; i < len; i++ ) {
        printf("%dth element value = %d\n", i, array[i]);
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
    //    print_array(nums,len);
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
    //    print_array(nums,len);
}

int* linear_search(int val, int *arr, size_t n){
    int *pArr;
    int *pArrEnd = arr+n;
    for(pArr = arr;pArr<pArrEnd;pArr++ ){
        if(*pArr == val){
            return pArr;
        }
    }
    
    return NULL;
}
