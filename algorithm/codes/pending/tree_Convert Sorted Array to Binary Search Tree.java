/*
108. Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

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
 I feel correct, but didn't pass in submission.
 */
  public TreeNode sortedArrayToBST(int[] nums) {
    if(nums==null || nums.length<1)
        return null;

    TreeNode root = new TreeNode(nums[nums.length/2]);
    for(int i=0;i<nums.length;i++){
        helper(root, nums[i]);
    }

    return root;
  }
    
  private TreeNode helper(TreeNode x, int val){
      if(x == null)
          return new TreeNode(val);

      if(val<x.val) 
          x.left = helper(x.left, val);
      else if(val>x.val)
          x.right = helper(x.right, val);
      else
          x.val = val;

      return x;
  }

