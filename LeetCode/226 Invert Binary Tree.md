```
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root: return None
        root.left, root.right = root.right, root.left
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root
```

## Leetcode
#### Recurse
```
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root: return None
        right = self.invertTree(root.right)
        left = self.invertTree(root.left)
        root.left, root.right = root.right, root.left
        return root
```
