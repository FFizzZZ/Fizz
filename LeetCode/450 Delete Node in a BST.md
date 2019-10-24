```
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        dummy = TreeNode(0)
        dummy.left = root
        self.dfs(root, dummy, True, key)
        return dummy.left
    def dfs(self, root, pre, left, key):
        if not root:
            return
        elif root.val == key:
            if root.left:
                tmp = node = root.left
                while node.right:
                    tmp = node
                    node = node.right
                node.right = root.right
                if node != root.left:
                    node.left = root.left
                    tmp.right = None
                if left:
                    pre.left = node
                else:
                    pre.right = node
            else:
                if left:
                    pre.left = root.right
                else:
                    pre.right = root.right            
        elif root.val > key:
            self.dfs(root.left, root, True, key)
        else:
            self.dfs(root.right, root, False, key)
```

## Leetcode

```
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root: return root
        if root.val > key:
            root.left = self.deleteNode(root.left, key)
        elif root.val < key:
            root.right = self.deleteNode(root.right, key)
        else:
            if not root.right:
                return root.left
            if not root.left:
                return root.right
            tmp = root.right
            while tmp.left:
                tmp = tmp.left
            root.val = tmp.val
            root.right = self.deleteNode(root.right, root.val)
        return root
```
