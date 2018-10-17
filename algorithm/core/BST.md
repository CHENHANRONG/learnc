# Binary Search Tree

### 中序遍历 in order 
```Java
public void inorder(TreeNode root, List < Integer > list) {
    if (root == null)
        return;
    inorder(root.left, list);
    list.add(root.val);
    inorder(root.right, list);
}
```
