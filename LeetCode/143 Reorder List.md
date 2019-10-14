## Leetcode
```
class Solution:
    def reorderList(self, head: ListNode) -> None:
        if not head or not head.next: return
        # Find the Middle of the List
        p1 = p2 = head
        while p2.next and p2.next.next:
            p1 = p1.next
            p2 = p2.next.next
        # Reverse the Second Half
        middle = p1
        last = p1.next
        while last.next:
            tmp = last.next
            last.next = tmp.next
            tmp.next = middle.next
            middle.next = tmp
        # Merge
        p1 = head
        while p1 != middle:
            tmp = middle.next
            middle.next = tmp.next
            tmp.next = p1.next
            p1.next = tmp
            p1 = tmp.next
```

```
class Solution:
    def reorderList(self, head: ListNode) -> None:
        if not head or not head.next: return 
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # reverse the second half of the list
        h = self.reverseList(slow.next)
        slow.next = None
        p, q = head, h
        # insert the second half the list into the first half appropriately
        while q:
            p_nxt = p.next; q_nxt = q.next
            p.next = q; q.next = p_nxt
            p = p_nxt; q = q_nxt
    
    def reverseList(self, head):
        if not head or not head.next: return head
        prev, cur = None, head
        while cur:
            tmp = cur.next
            cur.next = prev
            prev = cur
            cur = tmp
        return prev
```
