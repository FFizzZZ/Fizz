## Leetcode
```
class Solution(object):
    def distributeCoins(self, root):
        self.ans = 0
        
        def f(node):
            if not node: return 0
            l = f(node.left)
            r = f(node.right)
            
            self.ans += abs(l) + abs(r)
            
            return node.val + l + r - 1
        
        f(root)
        return self.ans
```

```
class Solution:
    def distributeCoins(self, root: TreeNode) -> int:
        self.res = 0

        def dfs(node):
            if node.left:
                dfs(node.left)
                node.val += node.left.val - 1
            if node.right:
                dfs(node.right)
                node.val += node.right.val - 1
            self.res += abs(node.val - 1)

        dfs(root)
        return self.res
```
