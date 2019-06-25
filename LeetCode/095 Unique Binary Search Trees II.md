```
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        return self.f(1, n) if n else []
    def f(self, l, r):
        ans = []
        for i in range(l, r + 1):
            for j in self.f(l, i - 1):
                for k in self.f(i + 1, r):
                    node = TreeNode(i)
                    node.left = j
                    node.right = k
                    ans.append(node)
        return ans or [None]
```

# use memo to record, faster
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        memo = {}
        def f(start, end):
            if (start, end) in memo:
                return memo[(start, end)]
            ans = []
            for i in range(start, end+1):
                left = f(start, i-1)
                right = f(i+1, end)
                for j in left:
                    for k in right:
                        node = TreeNode(i)
                        node.left = j
                        node.right = k
                        ans.append(node)
            memo[(start, end)] = ans or [None]
            return ans or [None]
        return f(1, n) if n else []



---------------------------

# I don't understand
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
