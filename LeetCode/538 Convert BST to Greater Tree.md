## Leetcode
#### Recurse
```
class Solution:
    def __init__(self):
        self.total = 0
    def convertBST(self, root: TreeNode) -> TreeNode:
        if root:
            self.convertBST(root.right)
            self.total += root.val
            root.val = self.total
            self.convertBST(root.left)
        return root
```

#### Iteration
```
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        total = 0
        node = root
        stack = []
        while node or stack:
            while node:
                stack.append(node)
                node = node.right
            node = stack.pop()
            total += node.val
            node.val = total
            node = node.left
        return root
```
