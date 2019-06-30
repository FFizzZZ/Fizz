```
class Solution:
    def flatten(self, root: TreeNode) -> None:
        if not root: return
        while root:
            if root.left:
                temp = root.right
                node = root.right = root.left
                while node.right:
                    node = node.right
                node.right = temp
                root.left = None
            root = root.right
```
