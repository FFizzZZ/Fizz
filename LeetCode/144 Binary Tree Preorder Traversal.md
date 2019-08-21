```
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root: return []
        return [root.val] + self.preorderTraversal(root.left) + self.preorderTraversal(root.right)
```

```
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                ans.append(root.val)
                root = root.left
            root = stack.pop().right
        return ans
```

```
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root: return []
        ans = []
        stack = [root]
        while stack:
            node = stack.pop()
            ans.append(node.val)
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
        return ans
```

```
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root: return []
        ans = []
        while root:
            if root.left:
                node = root.left
                while node.right and node.right != root:
                    node = node.right
                if node.right:
                    node.right = None
                    root = root.right
                else:
                    ans.append(root.val)
                    node.right, root = root, root.left
            else:
                ans.append(root.val)
                root = root.right
        return ans
```
