```
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root: return False
        sum -= root.val
        if not root.right and not root.left: return sum == 0
        return self.hasPathSum(root.left, sum) or self.hasPathSum(root.right, sum)
```

## Leecode
### Iteration
```
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        stack = [(root, root.val)]
        while stack:
            curr, val = stack.pop()
            if not curr.left and not curr.right:
                if val == sum:
                    return True
            if curr.right:
                stack.append((curr.right, val+curr.right.val))
            if curr.left:
                stack.append((curr.left, val+curr.left.val))
        return False
```

### Postorder Traversal
```
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        stack = []
        pre = None
        s = 0
        while root or stack:
            while root:
                s += root.val
                stack.append(root)
                root = root.left
            node = stack[-1]
            if not node.right and not node.left and s == sum:
                return True
            if node.right and node.right != pre:
                root = node.right
            else:
                s -= node.val
                pre = node
                stack.pop()
        return False
```
