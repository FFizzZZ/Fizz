## Leetcode
#### Recurse
```
class Solution:
    def __init__(self):
        self.ans = float('-inf')
    def maxPathSum(self, root: TreeNode) -> int:
        self.f(root)
        return self.ans
    def f(self, root):
        if not root: return 0
        left = self.f(root.left)
        right = self.f(root.right)
        self.ans = max(self.ans, left + right + root.val)
        return max(0, max(left, right) + root.val)
```
