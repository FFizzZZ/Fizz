```
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        self.ans = 0
        def dfs(root):
            if not root.left and not root.right:
                return root.val, root.val
            Max = Min = root.val
            if root.left:
                a, b = dfs(root.left)
                self.ans = max(self.ans, abs(root.val - a), abs(root.val - b))  
                Max = max(a, Max)
                Min = min(b, Min)
            if root.right:
                a, b = dfs(root.right)
                self.ans = max(self.ans, abs(root.val - a), abs(root.val - b))
                Max = max(a, Max)
                Min = min(b, Min)
            return Max, Min
        dfs(root)
        return self.ans
```

## Leetcode
            
```
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        def dfs(root, Max, Min):
            if not root:
                return Max - Min
            Max = max(Max, root.val)
            Min = min(Min, root.val)
            return max(dfs(root.left, Max, Min), dfs(root.right, Max, Min))
        return dfs(root, root.val, root.val)
```
