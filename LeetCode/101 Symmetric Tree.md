## Iterative
```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root: return True
        stack = [(root.left, root.right)]
        while stack:
            x, y = stack.pop()
            if not x or not y:
                if x or y: return False
                continue
            if x.val != y.val: return False
            stack.append((x.left, y.right))
            stack.append((x.right, y.left))
        return True
```

## Leetcode
## Recurse
```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root: return True
        return self.isMirror(root.left, root.right)
    def isMirror(self, p, q):
        if not p and not q: return True
        if not p or not q: return False
        return p.val == q.val and self.isMirror(p.left, q.right) and self.isMirror(p.right, q.left)
```
