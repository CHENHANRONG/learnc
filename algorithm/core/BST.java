


public class BST<Key extends Comparable<Key>, Value>
{
    private Node root;    //二叉树的根结点
    private class Node
    {
        private Key key;    //键
        private Value val;    //值
        private Node left, right;   //指向子树的链接
        private int N;    //以该节点为根的子树中的节点总数
        
        public Node(Key key, Value val, int N)
        {
            this.key = key;
            this.val = val;
            this.N = N;
        }
    }
    
    pubic int size()
    {
        return size(root);
    }
    
    
}
    
    
