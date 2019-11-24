## Leetcode
#### Brute Force
```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root: return 0
        mid = self.count(root, sum)
        left = self.pathSum(root.left, sum)
        right = self.pathSum(root.right, sum)
        return mid + left + right
    def count(self, root, sum):
        if not root: return 0
        sum -= root.val
        mid = 1 if sum == 0 else 0
        left = self.count(root.left, sum)
        right = self.count(root.right, sum)
        return mid + left + right
```
#### Recurse with memorization (really good!)
```
class Solution:
    def pathSum(self, root: TreeNode, target: int) -> int:
        self.ans = 0
        d = {0: 1}
        self.dfs(root, 0, target, d)
        return self.ans
    
    def dfs(self, root, cur, target, d):
        if not root: return 0
        cur += root.val
        self.ans += d.get(cur - target, 0)
        d[cur] = d.get(cur, 0) + 1
        self.dfs(root.left, cur, target, d)
        self.dfs(root.right, cur, target, d)
        d[cur] -= 1
```


```
class Solution(object):
    def pathSum(self, root, target):
        d = collections.defaultdict(int)
        d[0] = 1
        return self.dfs(root, 0, target, d)
    
    def dfs(self, root, cur, target, d):
        if not root: return 0
        cur += root.val
        ans = d[cur - target]
        d[cur] += 1
        ans += self.dfs(root.left, cur, target, d) + self.dfs(root.right, cur, target, d)
        d[cur] -= 1
        return ans
```
