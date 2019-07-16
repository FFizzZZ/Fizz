```
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root: return 0
        self.ans = 0
        self.f(root)
        return self.ans - 1
    def f(self, root):
        if not root: return 0
        left = self.f(root.left)
        right = self.f(root.right)
        val = left + right + 1
        if val > self.ans:
            self.ans = val
        ans = left
        if right > left:
            ans = right
        return ans + 1
```

