```
class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1:
            head = TreeNode(v)
            head.left = root
            return head
        self.f(root, v, d, 1)
        return root
    def f(self, root, v, d, depth):
        if not root: return
        if depth == d - 1:
            node = TreeNode(v)
            node.left = root.left
            root.left = node
            
            node = TreeNode(v)
            node.right = root.right
            root.right = node
        else:
            self.f(root.left, v, d, depth + 1)
            self.f(root.right, v, d, depth + 1)
```
