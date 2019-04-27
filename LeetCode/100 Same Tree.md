```
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def f(p, q):
            if not p and not q:
                return True
            if not p or not q:
                return False
            if p.val != q.val:
                return False
            return f(p.left, q.left) and f(p.right, q.right)
        return f(p, q)
```
