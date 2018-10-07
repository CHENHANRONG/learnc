
/*
a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

*/

    boolean res = true;
    
    private int depth(TreeNode root){
        // Add below line to come out of recursion quickly as soon as imbalance is found 
        if (!res) return 0;

        if(root == null)
            return 0;
        
        //check child balance here
        int l = depth(root.left);
        int r = depth(root.right);
        // res = Math.abs(l-r)>1?false:true;
        if(Math.abs(l-r)>1)
            res = false;
        
        return Math.max(l, r)+1;
    }
    public boolean isBalanced(TreeNode root) {
        if(root == null)
            return true;
        
        // boolean r = Math.abs(helper(root.left) - helper(root.right))>1?false:true;
        // boolean rl = isBalanced(root.left);
        // boolean rr = isBalanced(root.right);
        depth(root);
        return res;

    }
