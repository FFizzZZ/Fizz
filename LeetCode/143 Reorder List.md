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
