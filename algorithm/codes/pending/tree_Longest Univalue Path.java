/*
687. Longest Univalue Path

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.



*/



/* 
My init solution:

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
    int maxLen = 0;

    public int longestUnivaluePath(TreeNode root) {
        
        if(root == null)
            return 0;
        
        if(root.left == null && root.right==null){
            return 0;
        }else if(root.left == null  && root.right != null){
            if(root.val == root.right.val)
                return 1+longestUnivaluePath(root.right);
            else 
                return longestUnivaluePath(root.right);
        }else if(root.left != null  && root.right == null){
            if(root.val == root.left.val)
                return 1+longestUnivaluePath(root.left);
            else
                return longestUnivaluePath(root.left);
        }else{
            if(root.val == root.left.val  && root.val == root.right.val)
                maxLen = Math.max(2+longestUnivaluePath(root.left), 2+longestUnivaluePath(root.right));
            else if(root.val == root.left.val  && root.val != root.right.val)
                maxLen = Math.max(1+longestUnivaluePath(root.left),longestUnivaluePath(root.right));
            else if(root.val != root.left.val  && root.val == root.right.val){
                maxLen = Math.max(longestUnivaluePath(root.left),1+longestUnivaluePath(root.right));
            }else{
                maxLen = Math.max(longestUnivaluePath(root.left),longestUnivaluePath(root.right));
            }
        }
        
        return maxLen;
        
    }
}
