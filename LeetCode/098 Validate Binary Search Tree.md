## Recurse
```
class Solution:
    def isValidBST(self, root, left = float('-inf'), right = float('inf')):
        if not root: return True
        if root.val <= left or root.val >= right:
            return False
        return self.isValidBST(root.left, left, root.val) and self.isValidBST(root.right, root.val, right)
```
    
---------------------------

## Inorder Traversal
```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        stack = []
        val = float('-inf')
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if val >= root.val: return False
            val = root.val
            root = root.right
        return True
```

## Iteration (stack)
每次将左右子节点进栈
```
class Solution:
    def isValidBST(self, root):
        if not root: return True
        stack = [(root, float('-inf'), float('inf'))]
        while stack:
            root, left, right = stack.pop()
            if not root: continue
            if root.val >= right or root.val <= left: return False
            stack.append((root.right, root.val, right))
            stack.append((root.left, left, root.val))
        return True
```


