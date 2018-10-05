/*
107. Binary Tree Level Order Traversal II


Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

*/


/*
My init solution:
BFS reverse
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
    // BFS倒序
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
         List<List<Integer>> res = new ArrayList<List<Integer>>();
        
        if(root==null)
            return res;
        
       

        Queue q = new LinkedList<Integer>();
        q.add(root);
        while(q.size()>0){
            ArrayList<Integer> xlevel = new ArrayList<Integer>();
            int level_size = q.size();

            for(int i=0;i<level_size;i++){
                TreeNode tn = (TreeNode)q.poll();
                xlevel.add(tn.val);

                if(tn.left != null)
                    q.add(tn.left);
                if(tn.right != null)
                    q.add(tn.right);
            }
            
            res.add(xlevel);
        }
        Collections.reverse(res);
        return res; 
        
        
    }
}
