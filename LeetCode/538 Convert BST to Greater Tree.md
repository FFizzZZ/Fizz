#### Morris Traversal
```
class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        total = 0
        head = root
        while root:
            if root.right:
                node = root.right
                while node.left and node.left != root:
                    node = node.left
                if node.left:
                    total += root.val
                    root.val = total
                    node.left = None
                    root = root.left
                else:
                    node.left = root
                    root = root.right
            else:
                total += root.val
                root.val = total
                root = root.left
        return head
```

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

#### Morris Traversal
```
class Solution(object):
    def convertBST(self, root):
        def get_successor(node):
            succ = node.right
            while succ.left and succ.left != node:
                succ = succ.left
            return succ     
        total = 0
        node = root
        while node:
            if not node.right:
                total += node.val
                node.val = total
                node = node.left
            else:
                succ = get_successor(node)
                if not succ.left:
                    succ.left = node
                    node = node.right
                else:
                    succ.left = None
                    total += node.val
                    node.val = total
                    node = node.left
        return root
```
