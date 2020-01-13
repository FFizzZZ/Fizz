## By Comparsion of Nodes
```
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        return self.equal(s, t) or s and (self.isSubtree(s.left, t) or self.isSubtree(s.right, t))
        
    def equal(self, x, y):
        if not x and not y: return True
        if not x or not y: return False
        return x.val == y.val and self.equal(x.left, y.left) and self.equal(x.right, y.right)
```

## Fastest
```
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        if not s or not t:
            return not s and not t
        if s.val == t.val and self.isSubtree(s.left, t.left) and self.isSubtree(t.right, s.right):
            return True
        return (s.left and self.isSubtree(s.left, t)) or (s.right and self.isSubtree(s.right, t))
```
