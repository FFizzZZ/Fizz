```
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root: return True
        return True if self.f(root) else False
    def f(self, root):
        if not root: return 0
        left = self.f(root.left)
        right = self.f(root.right)
        if left is False or right is False: return False
        return abs(left - right) <= 1 and max(left, right) + 1
```

## Leetcode
### Iteration: Postorder Traversal
```
class Solution(object):
    def isBalanced(self, root):
        stack, node, last, depths = [], root, None, {}
        while stack or node:
            if node:
                stack.append(node)
                node = node.left
            else:
                node = stack[-1]
                if not node.right or last == node.right:
                    node = stack.pop()
                    left, right  = depths.get(node.left, 0), depths.get(node.right, 0)
                    if abs(left - right) > 1: return False
                    depths[node] = 1 + max(left, right)
                    last = node
                    node = None
                else:
                    node = node.right
        return True
```
