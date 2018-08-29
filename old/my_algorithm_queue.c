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



struct s_listnode {
    int element ;
    struct s_listnode* pnext ;
};
struct s_listnode* queue_buffer = NULL;   //start empty
struct s_listnode *prear = NULL;

void enqueue(int elem){
    struct s_listnode *new_node = (struct s_listnode*)malloc(sizeof(struct s_listnode));
    new_node->element = elem;
    new_node->pnext = NULL;
    if(prear){
        prear->pnext = new_node;
    }else{  //empty
        queue_buffer = new_node;
    }
    prear=new_node;
}
int dequeue(void){
    if(queue_buffer){
        struct s_listnode  *pelem = queue_buffer;
        int elem = queue_buffer->element;
        if(pelem == prear){  //if reach end
            prear = NULL;
            queue_buffer = NULL;
        }else{
            queue_buffer = pelem->pnext;
        }
        free(pelem);
        return elem;
    }else{
        return 0;
    }
}
