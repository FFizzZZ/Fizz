## Leetcode
### Iteration
```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root: return None
        node = root
        while node.left:
            p = node
            while p:
                p.left.next = p.right
                if p.next:
                    p.right.next = p.next.left
                p = p.next
            node = node.left
        return root
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
