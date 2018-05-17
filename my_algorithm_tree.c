

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
