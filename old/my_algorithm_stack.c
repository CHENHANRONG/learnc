struct s_listnode {
    int element ;
    struct s_listnode* pnext ;
};

struct s_listnode* stack_buffer = NULL;   //start empty

void push ( int elem ) {
     /* allocate new node */
    struct s_listnode *new_node = (struct s_listnode*) malloc (sizeof (struct s_listnode));
    new_node->pnext = stack_buffer ;
    new_node->element = elem ;
    stack_buffer = new_node ;
}

int pop ( void ) {
    if( stack_buffer ){
        struct s_listnode *pelem = stack_buffer ;
        int elem = stack_buffer->element;
        stack_buffer=pelem->pnext;
        free ( pelem ) ; //remove node from memory
        return elem ;
    }else{
        
        return 0; // or other spec ial value
    }
    
}
