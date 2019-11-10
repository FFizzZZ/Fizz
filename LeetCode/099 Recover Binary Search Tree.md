## Inorder Traversal
```
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        stack = []
        first, second = None, None
        pre = None
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if pre and root.val < pre.val:
                if not first:
                    first = pre
                second = root            
            pre = root
            root = root.right
        first.val, second.val = second.val, first.val
```
## Leetcode
## Morris Traversal
```
class Solution:
    def recoverTree(self, root):
        first = second = pre = None
        while root:
            if root.left:
                node = root.left
                while node.right and node.right != root:
                    node = node.right
                if not node.right:
                    node.right = root
                    root = root.left
                else:
                    node.right = None
                    if pre and pre.val > root.val:
                        if not first:
                            first = pre
                        second = root
                    pre = root
                    root = root.right
            else:
                if pre and pre.val > root.val:
                    if not first:
                        first = pre
                    second = root
                pre = root
                root = root.right
        first.val, second.val = second.val, first.val
```
```
class Solution:
    def recoverTree(self, root):
        first = second = pre = None
        while root:
            if pre and pre.val > root.val:
                if not first:
                    first = pre
                second = root
            if root.left:
                node = root.left
                while node.right and node.right != root:
                    node = node.right
                if not node.right:
                    node.right = root
                    root = root.left
                else:
                    node.right = None
                    pre = root
                    root = root.right
            else:
                pre = root
                root = root.right
        first.val, second.val = second.val, first.val
```
