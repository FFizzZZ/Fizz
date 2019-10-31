```
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
```

## Leetcode

```
class Solution:
    def countNodes(self, root):
        if not root:
            return 0
        left_node = root
        left_height = 0
        right_node = root
        right_height = 0
        while left_node:
            left_node = left_node.left
            left_height += 1
        while right_node:
            right_node = right_node.right
            right_height += 1
        if left_height == right_height:
            return 2 ** right_height - 1
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
```
        
```
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        left, right = map(self.depth, (root.left, root.right))
        if left == right:
            return 2 ** left + self.countNodes(root.right)
        else:
            return 2 ** right + self.countNodes(root.left)
    
    def depth(self, node):
        if not node:
            return 0
        return 1 + self.depth(node.left)
```
