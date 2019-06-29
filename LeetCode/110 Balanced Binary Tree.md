```
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root: return True
        return True if self.f(root) else False
    def f(self, root):
        if not root: return 0
        left = self.f(root.left)
        right = self.f(root.right)
        if left is False or right is False: return False
        return abs(left - right) <= 1 and max(left, right) + 1
```
