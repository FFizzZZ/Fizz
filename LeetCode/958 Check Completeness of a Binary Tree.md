```
class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        queue = [(root, 0)]
        pre = -1
        for node, idx in queue:
            if node:
                if idx != pre + 1:
                    return False
                pre = idx
                queue.append((node.left, 2 * idx + 1))
                queue.append((node.right, 2 * idx + 2))
        return True
```

## Leetcode

```
class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        if not root: return True
        queue = collections.deque([root])
        while queue:
            node = queue.popleft()
            if node.left:
                queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                else:
                    break
            else:
                if node.right:
                    return False
                break
        while queue:
            node = queue.popleft()
            if node.left or node.right:
                return False
        return True
```
