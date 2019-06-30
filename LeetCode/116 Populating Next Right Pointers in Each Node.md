## Leetcode
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
