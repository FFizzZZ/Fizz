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
class Solution(object):
    def pathSum(self, root, target):
        self.result = 0
        cache = {0:1}
        self.dfs(root, target, 0, cache)
        return self.result
    
    def dfs(self, root, target, currPathSum, cache):
        if not root: return  
        # calculate currPathSum and required oldPathSum
        currPathSum += root.val
        oldPathSum = currPathSum - target
        # update result and cache
        self.result += cache.get(oldPathSum, 0)
        cache[currPathSum] = cache.get(currPathSum, 0) + 1
        # dfs breakdown
        self.dfs(root.left, target, currPathSum, cache)
        self.dfs(root.right, target, currPathSum, cache)
        # when move to a different branch, the currPathSum is no longer available, hence remove one. 
        cache[currPathSum] -= 1
```
