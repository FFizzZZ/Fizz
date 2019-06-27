```
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p or not q:
            if p or q: return False
            return True
        if p.val != q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
```

```
class Solution:
    def isSameTree(self, p, q):
        if p and q:
            return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        return p is q
```

## Leetcode
## Iteration
```
from collections import deque
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        queue = deque([(p, q)])
        while queue:
            p, q = queue.popleft()
            if not self.check(p, q): return False
            if p:
                queue.append((p.left, q.left))
                queue.append((p.right, q.right))
        return True
    def check(self, p, q):
        if not p and not q: return True
        if not q or not p: return False
        if p.val != q.val: return False
        return True
```
## Recurse
Interesting!
```
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def t(n):
            return n and (n.val, t(n.left), t(n.right))
        return t(p) == t(q)
```
