```
import queue
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        q = queue.deque([root])
        ans = None
        while q:
            n = len(q)
            for _ in range(n):
                node = q.popleft()
                if node.right:
                    q.append(node.right)
                if node.left:
                    q.append(node.left)
            ans = node.val     
        return ans
```

## Leetcode

```
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        queue = [root]
        for node in queue:
            queue += filter(None, (node.right, node.left))
        return node.val
```
