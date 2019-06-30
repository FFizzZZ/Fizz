```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root: return
        pre = root
        cur = None
        while pre.left:
            cur = pre
            while cur:
                cur.left.next = cur.right
                if cur.next:
                    cur.right.next = cur.next.left
                cur = cur.next
            pre = pre.left
        return root
```
