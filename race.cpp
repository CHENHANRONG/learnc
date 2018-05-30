/*
C not designed for multithreading
• No notion of atomic operations in C
• Increment cnt++; maps to three assembly operations:
1. load cnt into a register
2. increment value in register
3.	 save new register value as new cnt
• So what happens if thread interrupted in the middle?
• Race condition! 
*/

#include <cstdlib>
# include <cstdio>
//#include <cstring>
#include "race.cpp"
#include <pthread.h>

using namespace std;


unsigned int cnt = 0;

void *count(void *arg)  //thread body
{
    int i;
    for(i=0;i<10000;i++){
        cnt++;
    }
    return NULL;
}


//==============================================================================
int main ( int argc , char *argv [ ] )
{
    pthread_t tids[4];
    int i;
    for(i = 0;i<4; i++){
        pthread_create(&tids[i], NULL, count, NULL);
    }
    
    for(i=0;i<4;i++){
        pthread_join(tids[i],NULL);
    }
    
    printf("cnt=%u\n", cnt);
    
    return EXIT_SUCCESS;
}
