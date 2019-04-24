```
class Solution(object):
    def isValidBST(self, root, left = float('inf'), right = float('-inf')):
        if not root: return True
        if root.val >= left or root.val <= right:
            return False
        return self.isValidBST(root.left, min(left, root.val), right) and \
    self.isValidBST(root.right, left, max(right, root.val))
```
    
---------------------------------------

## 检验中序排序是否严格递增
```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        inorder = []
        def f(node):
            if not node:
                return
            f(node.left)
            inorder.append(node.val)
            f(node.right)
        f(root)
        for i in range(1, len(inorder)):
            if inorder[i-1] >= inorder[i]:
                return False
        return True
```
