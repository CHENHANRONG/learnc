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


/*
DFS solution:

Algorithm

One of the methods to solve the given problem is to make use of Depth First Search. In DFS, we try to exhaust each branch of the given tree during the tree traversal before moving onto the next branch.

To make use of DFS to solve the given problem, we make use of two lists countcount and resres. Here, count[i]count[i] refers to the total number of nodes found at the i^{th}i 
th
  level(counting from root at level 0) till now, and res[i]res[i] refers to the sum of the nodes at the i^{th}i 
th
  level encountered till now during the Depth First Search.

We make use of a function average(t, i, res, count), which is used to fill the resres and countcount array if we start the DFS from the node tt at the i^{th}i 
th
  level in the given tree. We start by making the function call average(root, 0, res, count). After this, we do the following at every step:

Add the value of the current node to the resres(or sumsum) at the index corresponding to the current level. Also, increment the countcount at the index corresponding to the current level.

Call the same function, average, with the left and the right child of the current node. Also, update the current level used in making the function call.

Repeat the above steps till all the nodes in the given tree have been considered once.

Populate the averages in the resultant array to be returned.

The following animation illustrates the process.

Complexity Analysis

Time complexity : O(n)O(n). The whole tree is traversed once only. Here, nn refers to the total number of nodes in the given binary tree.

Space complexity : O(h)O(h). resres and countcount array of size hh are used. Here, hh refers to the height(maximum number of levels) of the given binary tree. Further, the depth of the recursive tree could go upto hh only.

*/

public List < Double > averageOfLevels(TreeNode root) {
        List < Integer > count = new ArrayList < > ();
        List < Double > res = new ArrayList < > ();
        average(root, 0, res, count);
        for (int i = 0; i < res.size(); i++)
            res.set(i, res.get(i) / count.get(i));
        return res;
}
public void average(TreeNode t, int i, List < Double > sum, List < Integer > count) {
    if (t == null)
        return;
    if (i < sum.size()) {
        sum.set(i, sum.get(i) + t.val);  // level i sum
        count.set(i, count.get(i) + 1);  // level i count
    } else {
        sum.add(1.0 * t.val);
        count.add(1);
    }
    average(t.left, i + 1, sum, count);  // level i+1 sum
    average(t.right, i + 1, sum, count);  // level i+1 count
}
