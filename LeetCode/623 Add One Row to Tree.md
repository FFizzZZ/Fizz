```
class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1:
            head = TreeNode(v)
            head.left = root
            return head
        self.f(root, v, d, 1)
        return root
    def f(self, root, v, d, depth):
        if not root: return
        if depth == d - 1:
            node = TreeNode(v)
            node.left = root.left
            root.left = node
            
            node = TreeNode(v)
            node.right = root.right
            root.right = node
        else:
            self.f(root.left, v, d, depth + 1)
            self.f(root.right, v, d, depth + 1)
```

## Leetcode
#### Iterative DFS
```
class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1:
            head = TreeNode(v)
            head.left = root
            return head
        stack = [(root, 1)]
        while stack:
            node, depth = stack.pop()
            if not node: continue
            if depth == d - 1:
                new = TreeNode(v)
                new.left = node.left
                node.left = new

                new = TreeNode(v)
                new.right = node.right
                node.right = new
            else:
                stack.append((node.left, depth + 1))
                stack.append((node.right, depth + 1))
        return root
```

```
class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1:
            head = TreeNode(v)
            head.left = root
            return head
        stack = [root]
        depth = 1
        while depth < d - 1:
            tmp = []
            while stack:
                node = stack.pop()
                if node.left: tmp.append(node.left)
                if node.right: tmp.append(node.right)
            depth += 1
            stack = tmp
        
        while stack:
            node = stack.pop()
            tmp = node.left
            new = TreeNode(v)
            new.left = tmp
            node.left = new
            
            tmp = node.right
            new = TreeNode(v)
            new.right = tmp
            node.right = new
            
        return root
```
