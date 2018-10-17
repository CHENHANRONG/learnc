/*
637. Average of Levels in Binary Tree


Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

*/

/*
My init solution:
BFS with size
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

public List<Double> averageOfLevels(TreeNode root) {
    //BFS WITH SIZE
    Queue<TreeNode> q = new LinkedList<TreeNode>();
    q.add(root);
    int levelSize = 1;

    List<Double> levelAvg = new ArrayList<Double>();

    while(!q.isEmpty()){
        double levelSum = 0.0;
        for(int i=0;i<levelSize; i++){
            TreeNode x = q.poll();
            levelSum += 1.0*x.val;
            if(x.left != null)
                q.add(x.left);
            if(x.right != null)
                q.add(x.right);
        }
        levelAvg.add(levelSum/levelSize);
        levelSize = q.size();
    }

    return levelAvg;
}
