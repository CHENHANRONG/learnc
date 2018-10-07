/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.

*/

/*
Improved one
*/


    boolean res = true;
    
    private int helper(TreeNode root){
        // Add below line to come out of recursion quickly as soon as imbalance is found 
        if (!res) return 0;

        if(root == null)
            return 0;
        
        //check child balance here
        int l = helper(root.left);
        int r = helper(root.right);
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
        helper(root);
        return res;

    }


/*
My init solution:
think: recursively check root, root's left child, and root's right child, if they are balanced.
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    private int helper(TreeNode root){
        if(root == null)
            return 0;
        
        return Math.max(helper(root.left), helper(root.right))+1;
    }
    public boolean isBalanced(TreeNode root) {
        if(root == null)
            return true;
        
        boolean r = Math.abs(helper(root.left) - helper(root.right))>1?false:true;
        boolean rl = isBalanced(root.left);
        boolean rr = isBalanced(root.right);
        return r&&rl&&rr;

    }
}
