int queue_buffer[MAXSIZE];
int icount = 0;
int ifront = 0;
void enqueue(int elem){
    if(icount<100){
        queue_buffer[icount] = elem;
        icount++;
    }
}
int dequeue(void){
    if(icount>0){
        icount--;
        return queue_buffer[ifront++];
    }else{
        return 0;
    }
}
