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
                tmp = None
                node = root.left
                while node.right:
                    tmp = node
                    node = node.right
                if tmp:
                    tmp.right = node.left
                    node.left = root.left
                node.right = root.right
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
