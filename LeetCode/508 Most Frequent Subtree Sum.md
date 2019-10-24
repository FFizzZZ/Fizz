```
class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        if not root: return 
        d = collections.defaultdict(int)
        self.dfs(root, d)
        Max = max(d.values())
        return [key for key, value in d.items() if value == Max]
    def dfs(self, root, d):
        if not root:
            return 0
        val = root.val + self.dfs(root.left, d) + self.dfs(root.right, d)
        d[val] += 1
        return val
```
