```
class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1 or not t2: return t1 or t2
        node = TreeNode(t1.val + t2.val)
        node.left = self.mergeTrees(t1.left, t2.left)
        node.right = self.mergeTrees(t1.right, t2.right)
        return node
```

## Leetcode
#### Iteration
```
class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1: return t2
        stack = [(t1, t2)]
        while stack:
            node1, node2 = stack.pop()
            if not node1 or not node2:
                continue
            node1.val += node2.val
            if not node1.left:
                node1.left = node2.left
            else:
                stack.append((node1.left, node2.left))
            if not node1.right:
                node1.right = node2.right
            else:
                stack.append((node1.right, node2.right))
        return t1
```
