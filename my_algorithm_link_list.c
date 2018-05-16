

struct node{
    int data;
    struct node* next;
};

struct node* head;


struct node* new_node(int data){
    struct node* pn=(struct node*)malloc(sizeof(node));
    if(pn!=NULL){
        pn->data = data;
        pn->next = NULL;
    }
    return pn;
}
