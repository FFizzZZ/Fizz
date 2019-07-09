## Leetcode
#### Recurse
```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root or root == p or root == q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        return root if left and right else left or right
```

```
class Solution:
    def __init__(self):
        self.ans = None
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.f(root, p, q)
        return self.ans
    def f(self, root, p, q):
        if not root: return False
        left = self.f(root.left, p, q)
        right = self.f(root.right, p, q)
        mid = root == p or root == q
        if left + right + mid == 2:
            self.ans = root
        return left or right or mid
```

#### Iteration
```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        stack = [root]
        d = {root: None}
        while p not in d or q not in d:
            node = stack.pop()
            if node.left:
                stack.append(node.left)
                d[node.left] = node
            if node.right:
                stack.append(node.right)
                d[node.right] = node
        s = set()
        while p:
            s.add(p)
            p = d[p]
        while q not in s:
            q = d[q]
        return q
```

```
class Solution:
    def lowestCommonAncestor(self, root, p, q):
        def path(root, goal):
            path, stack = [], [root]
            while stack:
                node = stack.pop()
                if node:
                    if node not in path[-1:]:
                        path.append(node)
                        if node == goal:
                            return path
                        stack += node, node.right, node.left
                    else:
                        path.pop()
        return [a for a, b in zip(path(root, p), path(root, q)) if a == b][-1]
```
