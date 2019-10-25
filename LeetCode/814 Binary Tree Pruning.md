```
class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        left = self.pruneTree(root.left)
        right = self.pruneTree(root.right)
        if not left:
            root.left = None
        if not right:
            root.right = None
        if not root.val and not left and not right:
            return None
        else:
            return root
```
