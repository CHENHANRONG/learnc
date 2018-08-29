
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void print_array(float array[], int len){
    puts("===========start to print array:");
    for(int i = 0; i < len; i++ ) {
        printf("%dth element value = %f\n", i, array[i]);
    }
    puts("===========end to print array.");
}


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


int main(void){
    int len = 10;
    float testnums[10];
    for(int i = 0; i < len; i++ ) {
        testnums[i] = rand();
    }
    
    bubbleSort1(testnums, 10);
    bubbleSort2(testnums,10);
    
}
