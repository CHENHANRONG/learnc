

struct tnode{
    int data;
    struct tnode* left;
    struct tnode* right;
};

/*
 Traversal (printing,searching):
 • pre-order: root, left subtree, right subtree
 • Inorder: left subtree, root, right subtree
 • post-order: right subtree, right subtree, root
*/

struct tnode* addnode(struct tnode* root, int data){
    struct tnode *newnode = NULL;
    if(root == NULL){
        /* allocate new node, return this new node as new root */
        newnode = (struct tnode*)malloc(sizeof(tnode));
        newnode->data=data;
        newnode->left = NULL;
        newnode->right = NULL;
    }else if( data < root->data ){
        root->left = addnode(root->left, data);
    }else{
        root->right = addnode(root->right, data);
    }
    return newnode;
}


////////////////////////////////////////////////////////

struct binary_tree_node{
    char *node_str;
    unsigned int count;
    struct binary_tree_node *lchild;  //left child
    struct binary_tree_node *rchild;  //right child
};
typedef struct binary_tree_node btnode;

btnode * malloc_new_btnode(char *instr){
    btnode *new_node = (btnode*)malloc(sizeof(btnode));
    if(new_node == NULL){
        //handle malloc exception
    }else{
        new_node->node_str = instr;
        new_node->count = 1;
        strcpy(new_node->node_str,instr);
        new_node->lchild = NULL;
        new_node->rchild = NULL;
    }
    return new_node;
}


btnode * add_btnode(btnode *nodex, char *instr){
  
    if(instr == NULL){
        //exception handle
        return NULL;
    }else{  // if instr is not NULL
        if(nodex == NULL){
            //new node shoud be added
            nodex = malloc_new_btnode(instr);
        }else{
            //if xnode is not NULL
            char *nstr = nodex->node_str;  // node text
            int cmp = strcmp(instr, nstr);  //str compare
            if( cmp == 0){  //find node equal to input str
                nodex->count++;
            }else if(strcmp(instr, nstr)<0){  // instr < current nodestr, do in lchild tree
                nodex->lchild = add_btnode(nodex->lchild, instr); //recursivly do in left subtree
            }else{  // instr > current nodestr, do in right child tree
                nodex->rchild = add_btnode(nodex->rchild, instr); //recursivly do in left subtree
            }
        }
    }
    
    //not work as expected, return NULL
    return nodex;
}


void tree_print(btnode *nodex){
    if(nodex == NULL){
        // do nothing
    }else{
        tree_print(nodex->lchild);
        printf("%4d  %s\n", nodex->count, nodex->node_str);
        tree_print(nodex->rchild);
    }
}
