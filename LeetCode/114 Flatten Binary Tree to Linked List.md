```
class Solution:
    def flatten(self, root: TreeNode) -> None:
        if not root: return
        while root:
            if root.left:
                node = root.left
                while node.right:
                    node = node.right
                node.right = root.right
                root.right = root.left
                root.left = None
            root = root.right
```

## Leetcode
### Recurse
```
class Solution:
    def __init__(self):
        self.prev = None
    def flatten(self, root: TreeNode) -> None:
        if not root: return
        self.flatten(root.right)
        self.flatten(root.left)
        root.right = self.prev
        root.left = None
        self.prev = root
```

```
class Solution:
    def flatten(self, root: TreeNode) -> None:
        self.f(root, None)
    def f(self, root, pre):
        if not root: return pre
        pre = self.f(root.right, pre)
        root.right = self.f(root.left, pre)
        root.left = None
        return root
```
