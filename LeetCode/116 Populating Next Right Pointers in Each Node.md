## Leetcode
### Iteration
```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        p = root
        while root and root.left:
            node = root
            while node:
                node.left.next = node.right
                if node.next:
                    node.right.next = node.next.left
                node = node.next
            root = root.left
        return p
```

### Recurse
```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root: return
        if root.left:
            root.left.next = root.right
            if root.next:
                root.right.next = root.next.left
        self.connect(root.left)
        self.connect(root.right)
        return root
```

```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root: return None
        self.f(root.left, root.right)
        return root
    def f(self, l, r):
        if not l: return
        l.next = r
        self.f(l.left, l.right)
        self.f(l.right, r.left)
        self.f(r.left, r.right)
```
