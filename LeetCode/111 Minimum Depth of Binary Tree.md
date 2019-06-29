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
                flag = 1
                if node.left: 
                    queue.append(node.left)
                    flag = 0
                if node.right:
                    queue.append(node.right)
                    flag = 0
                if flag: return h
```

```
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root: return 0
        left = self.minDepth(root.left)
        right = self.minDepth(root.right)
        if not left or not right:
            return max(left, right) + 1
        return min(left, right) + 1
```

