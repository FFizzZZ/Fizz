```
class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        return self.f(t1, t2)
    def f(self, t1, t2):
        if not t1 or not t2: return t1 or t2
        node = TreeNode(t1.val + t2.val)
        node.left = self.f(t1.left, t2.left)
        node.right = self.f(t1.right, t2.right)
        return node
```
