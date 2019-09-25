```
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root: return 0
        self.ans = 0
        self.dfs(root, 0)
        return self.ans
        
    def dfs(self, node, cur):
        cur = 10 * cur + node.val
        if not node.left and not node.right:
            self.ans += cur
            return
        if node.left:
            self.dfs(node.left, cur)
        if node.right:
            self.dfs(node.right, cur)
```
