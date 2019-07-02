## Leetcode
#### Recurse
```
class Solution:
    def __init__(self):
        self.ans = float('-inf')
    def maxPathSum(self, root: TreeNode) -> int:
        self.pathdown(root)
        return self.ans
    def pathdown(self, root):
        if not root: return 0
        left = max(0, self.pathdown(root.left))
        right = max(0, self.pathdown(root.right))
        self.ans = max(self.ans, left + right + root.val)
        return max(left, right) + root.val
```
