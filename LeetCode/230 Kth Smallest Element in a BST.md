```
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        while root:
            if root.left:
                node = root.left
                while node.right and node.right != root:
                    node = node.right
                if node.right:
                    k -= 1
                    if k == 0: return root.val
                    node.right = None
                    root = root.right
                else:
                    node.right = root
                    root = root.left
            else:
                k -= 1
                if k == 0: return root.val
                root = root.right
```

## Leetcode
```
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        return self.inorder(root)[k - 1]
    def inorder(self, root):
        if not root: return []
        return self.inorder(root.left) + [root.val] + self.inorder(root.right)
```

```
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            k -= 1
            if not k: return root.val
            root = root.right
```
