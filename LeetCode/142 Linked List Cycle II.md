```
class Solution(object):
    def detectCycle(self, head):
        p, q = head, head
        while q and q.next:
            q = q.next.next
            p = p.next
            if p == q: break
        if not q or not q.next: return None
        x = head
        while x != q:
            x = x.next
            q = q.next
        return x
```
