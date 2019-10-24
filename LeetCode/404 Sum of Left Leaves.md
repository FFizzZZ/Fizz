```
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        return self.dfs(root, False)
    def dfs(self, root, left):
        if not root:
            return 0
        elif left and not root.left and not root.right:
            return root.val
        return self.dfs(root.left, True) + self.dfs(root.right, False)
```

## Leetcode
```
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if not root: return 0
        val = 0
        if root.left and not root.left.left and not root.left.right:
            val = root.left.val
        return val + self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)
```
