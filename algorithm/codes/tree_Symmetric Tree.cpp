/*
1360. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example
For example, this binary tree {1,2,2,3,4,4,3} is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following {1,2,2,#,3,#,3} is not:

    1
   / \
  2   2
   \   \
   3    3
Notice
Bonus points if you could solve it both recursively and iteratively.
*/

/*
Java 
*/

    /**
     * @param root: root of the given tree
     * @return: whether it is a mirror of itself
     */
     //正确的
     public boolean isSymmetric(TreeNode root) {
            if(root == null)
                return true;
                
            return helper(root.left, root.right);

        }
        
        public boolean helper(TreeNode left, TreeNode right){
            if(left == null && right == null)
                return true;
            else if(left == null || right == null)
                return false;
            else
                return helper(left.left, right.right) && helper(left.right, right.left);
        }
        
     //有问题的
    public static boolean isSymmetric(TreeNode root) {
        // Write your code here
        if(root == null)
            return true;

        // boolean quitFlag = false;

        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while(!(q.isEmpty())){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode pNode = q.poll();

                if(pNode == null){
                    return true;
                }

                q.add(pNode.left);
                q.add(pNode.right);
            }

            if(!checkArraySymmetric(q)){
                return false;
            }
        }


        return true;
    }

    public static boolean checkArraySymmetric(Queue<TreeNode> list2){
        ArrayList<TreeNode> list = new ArrayList(list2);
        for(int i=0;i<list.size()/2;i++){
            if(list.get(i) == null && list.get(list.size()-1-i) == null){
                continue;
            }else if(list.get(i) == null || list.get(list.size()-1-i) == null){
                return false;
            }


            if(list.get(i).val != list.get(list.size()-1-i).val)
                    return false;
            
        }

        return true;
    }
