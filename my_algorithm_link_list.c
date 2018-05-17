

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

struct node* add_frond(struct node* head, int data){
    struct node *np = new_node(data);
    if(np == NULL){
        return head;
    }else{
        head->next = np;
        return head;
    }
}

void apply(struct node *phead, void (*fp)(void *, void *), void *arg){
    struct node *p = phead;
    while(p!=NULL){
        fp(p, arg);
        p = p->next;
    }
}
