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


```
class Solution:
    def isSameTree(self, p, q):
        if p and q:
            return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        return p is q
```
