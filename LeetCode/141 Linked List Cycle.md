```
class Solution(object):
    def hasCycle(self, head):
        p, q = head, head
        while q and q.next:
            p = p.next
            q = q.next.next
            if p == q: return True
        return False
```

## Leetcode
```
class Solution(object):
    def hasCycle(self, head):
        if not head or not head.next:
            return False
        slow, fast = head, head.next
        while slow != fast:
            if not fast or not fast.next:
                return False
            slow = slow.next
            fast = fast.next.next
        return True
```

```
class Solution(object):
    def hasCycle(self, head):
        try:
            slow = head
            fast = head.next
            while slow is not fast:
                slow = slow.next
                fast = fast.next.next
            return True
        except:
            return False
```
