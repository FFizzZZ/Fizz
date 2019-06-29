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
        stack = []
        pre = None
        depth = {}
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            node = stack[-1]
            if not node.right or node.right == pre:
                stack.pop()
                pre = node
                left, right = depth.get(node.left, 0), depth.get(node.right, 0)
                if abs(left - right) > 1: return False
                depth[node] = max(left, right) + 1
            else:
                root = node.right
        return True
```
