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
