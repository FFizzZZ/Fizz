```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0
        count = 0
        queue = [root]
        while queue:
            count += 1
            for _ in range(len(queue)):
                root = queue.pop(0)
                if root.left: queue.append(root.left)
                if root.right: queue.append(root.right)
        return count
```

## Leetcode
## Recurse
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
```
