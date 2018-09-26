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

    public int size()
    {
        return size(root);
    }


    /**
     * 取得以x为根节点的子树的节点数量
     * @param x
     * @return
     */
    private int size(Node x) {
        if(x == null)
            return 0;
        else
            return x.N;
    }



    public Value get(Key key){
        return get(root, key);
    }

    /**
     * 在以x为根节点的子树中查找并返回key所对应的值
     * @param x
     * @param key
     * @return
     */
    private Value get(Node x, Key key) {
        if(x==null)
            return null;

        int cmp = key.compareTo(x.key);
        if(cmp<0)
            return get(x.left, key);    // key < x.key, find x's left child
        else if(cmp>0)
            return get(x.right, key);   // key > x.key, find x's right child
        else
            return x.val;   // equal, then return x's value

    }


    /**
     * 查找key值， 找到则更新它的值， 负责为它创建一个新的节点
     * @param key
     * @param val
     */
    public void put(Key key, Value val){
         root = put(root, key, val);
    }


    /**
     * 如果key存在于以x为根节点的子树中则更新它的值。
     * 负责将创建新的节点以key和val为键值对， 插入到该子树中
     * @param x
     * @param key
     * @param val
     * @return
     */
    private Node put(Node x, Key key, Value val) {
        if(root == null)
            return new Node(key, val, 1);

        int cmp = key.compareTo(x.key);
        if(cmp<0)
            x.left = put(x.left, key, val);
        else if(cmp>0)
            x.right = put(x.right, key, val);
        else x.val = val;

        x.N = size(x.left) + size(x.right) +1;  // +1 for this x

        return x;
    }


}
