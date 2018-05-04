/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<stdio.h>
#include<stdlib.h>

/* analysis:
 * step 1: read in all inputs
 * step 2: for range pair, set it to a array, and mode 2 to get the (start, end)
 * pair.
 * step 3: set the line string into a char* array, loop the (start,end) pair to
 * get the new range of string.
 * step 4: print out.
 */

/* what book does:
 * 
 */

/* declear functions */

#define MAX_COLS 20
#define MAX_INPUT 1000


extern int read_column_numbers(int *, int);
extern void rereange(char *, char const, int , int const *);

/*
 main function
 */
int main(int narg, char** argc){
    int n_columns;
    int columns[MAX_COLS];
    
    char inputs[MAX_INPUT];
    char outputs[MAX_INPUT];
    
    //call func to read columns
    n_columns = read_column_numbers(columns, MAX_COLS);

}

/*
 * read column index
*/
int read_column_numbers(int columns[], int max)
{
    int num = 0;
    int ch;
    
    //read in the range number pair
    while(num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
    {
        num++;
    }
    
    //check the range numbers are in pair.
    if(num % 2 !=0 ){
        puts("Last column number is not paired");
        exit(EXIT_FAILURE);
    }
    
    while( (ch=getchar()) != EOF && ch != '\n');
    
    return num;
}
