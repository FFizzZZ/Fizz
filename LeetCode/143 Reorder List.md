## Leetcode
```
class Solution:
    def reorderList(self, head: ListNode) -> None:
        if not head or not head.next: return
        # Find the middle of the List
        p1 = p2 = head
        while p2.next and p2.next.next:
            p1 = p1.next
            p2 = p2.next.next
        # Reverse the second half
        pre = p1
        cur = p1.next
        while cur.next:
            tmp = cur.next
            cur.next = tmp.next
            tmp.next = pre.next
            pre.next = tmp
        # reorder
        p1 = head
        p2 = pre.next
        while p1 != pre:
            pre.next = p2.next
            p2.next = p1.next
            p1.next = p2
            p1 = p2.next
            p2 = pre.next
```
