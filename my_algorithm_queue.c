#define MAXSIZE 100

int queue_buffer[MAXSIZE];
int icount = 0;
int ifront = 0;
void enqueue(int elem){
    if(icount<100){
        queue_buffer[ (ifront + icount) % MAXSIZE ] = elem;
        icount++;
    }
}
int dequeue(void){
    if(icount>0){
        int elem = queue_buffer[ifront++];
        icount--;
        //ifront++;
        if(ifront==MAXSIZE){
            ifront = 0;
        }
        return elem;
    }else{
        return 0;
    }
}
