/*

653. Two Sum IV - Input is a BST


Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False


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
 
 
 /*
 my init solution:
 set + DFS
 */

Set<Integer> set = new HashSet<Integer>();
    
public boolean findTarget(TreeNode root, int k) {
    //hash + dfs
    if(root == null)
        return false;
    else{
        int target = k - root.val;
        if(set.contains(target)){
            return true;
        }else{
            set.add(root.val);
            boolean left = false;
            boolean right = false;
            if(root.left != null)
                left = findTarget(root.left, k);
            if(root.right != null)
                right = findTarget(root.right, k);

            return left || right;
        }

    }
}


/*
other solutions:
https://leetcode.com/articles/two-sum-iv/
*/
