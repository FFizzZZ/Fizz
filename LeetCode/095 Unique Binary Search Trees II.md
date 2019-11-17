## Recursion
```
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        return self.helper(1, n) if n else []
        
    def helper(self, l, r):
        ans = []
        for i in range(l, r + 1):
            for left in self.helper(l, i - 1):
                for right in self.helper(i + 1, r):
                    node = TreeNode(i)
                    node.left = left
                    node.right = right
                    ans.append(node)
        return ans or [None]
```

#### With Memorization
```
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        memo = dict()
        return self.helper(1, n, memo) if n else []
        
    def helper(self, l, r, memo):
        if (l, r) in memo: return memo[l, r]
        ans = []
        for i in range(l, r + 1):
            for left in self.helper(l, i - 1, memo):
                for right in self.helper(i + 1, r, memo):
                    node = TreeNode(i)
                    node.left = left
                    node.right = right
                    ans.append(node)
        ans = ans or [None]
        memo[l, r] = ans
        return ans
```




## Dynamic Programming
```
class Solution:
    def generateTrees(self, n):
        if n == 0: return []
        dp = [[[None]] * (n + 2) for _ in range(n + 2)]
        for i in range(n, 0, -1):
            dp[i][i] = [TreeNode(i)]
            for j in range(i + 1, n + 1):
                dp[i][j] = []
                for k in range(i, j + 1):
                    for left in dp[i][k - 1]:
                        for right in dp[k + 1][j]:
                            node = TreeNode(k)
                            node.left = left
                            node.right = right
                            dp[i][j].append(node)
        return dp[1][n]
```
#### Another direction
```
class Solution:
    def generateTrees(self, n):
        if n == 0:
            return []
        tree_list = [[[None]] * (n + 2) for i in range(n + 2)]
        for i in range(1, n + 1):
            tree_list[i][i] = [TreeNode(i)]
            for j in reversed(range(1, i)):
                tree_list[j][i] = []
                for k in range(j, i + 1):
                    for left in tree_list[j][k - 1]:
                        for right in tree_list[k + 1][i]:
                            root = TreeNode(k)
                            (root.left, root.right) = (left, right)
                            tree_list[j][i].append(root)
        return tree_list[1][n]
```
