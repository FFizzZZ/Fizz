```
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        return self.f(root)[0]
    def f(self, root):
        if not root:
            return 0, 0
        left_diff, left = self.f(root.left)
        right_diff, right = self.f(root.right)
        diff = abs(left - right)
        return left_diff + right_diff + diff, left + right + root.val
```

## Leetcode

```
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        self.ans = 0
        self.f(root)
        return self.ans
    def f(self, root):
        if not root:
            return 0
        left = self.f(root.left)
        right = self.f(root.right)
        self.ans += abs(left - right)
        return left + right + root.val
```
