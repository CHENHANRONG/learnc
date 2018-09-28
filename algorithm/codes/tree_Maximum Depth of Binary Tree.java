/*
104. Maximum Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

*/


/*
My init solution:
思路： Maximum Depth of Binary Tree = max(left child, right child)+1
*/

    public int maxDepth(TreeNode root) {
        //max depth should be max(depth of left child , depth of right child)+1
        if(root == null)
            return 0;
        
        return Math.max(maxDepth(root.left), maxDepth(root.right))+1;
    }
