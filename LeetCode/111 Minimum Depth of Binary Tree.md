```
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root: return 0
        queue = [root]
        h = 0
        while queue:
            h += 1
            for _ in range(len(queue)):
                node = queue.pop(0)
                if not node.left and not node.right: return h
                if node.left: 
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
```

```
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root: return 0
        left = self.minDepth(root.left)
        right = self.minDepth(root.right)
        if not left or not right:
            return left + right + 1
        return min(left, right) + 1
```

