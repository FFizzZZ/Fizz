## Leetcode
#### Change the value
```
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root: return
        if root.val > key:
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        else:
            if not root.right:
                return root.left
            node = root.right
            while node.left:
                node = node.left
            root.val = node.val
            root.right = self.deleteNode(root.right, root.val)
        return root
```

#### Reconnnect (Better)
```
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root: return root
        if root.val < key:
            root.right = self.deleteNode(root.right, key)
        elif root.val > key:
            root.left = self.deleteNode(root.left, key)
        else:
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            else:
                node = root.right
                pre = None
                while node.left:
                    pre = node
                    node = node.left
                if not pre:
                    node.left = root.left
                    return node
                pre.left = node.right
                node.left = root.left
                node.right = root.right
                return node
        return root
```
