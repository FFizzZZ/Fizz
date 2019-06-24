## Recursive
```
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root: return []
        return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)
```
------------------------------------------------
## Stack
```
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        stack = []
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            ans.append(root.val)
            root = root.right
        return ans
```

## Morris Traversal
```
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        while root:
            if not root.left:
                ans.append(root.val)
                root = root.right
            else:
                temp = p = root.left
                while p.right:
                    p = p.right
                p.right = root
                root.left = None   # Pay attention!
                root = temp
        return ans
```
        
