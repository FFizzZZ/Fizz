## Iteration
```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        p = head
        while p and p.next:
            if p.val == p.next.val:
                pre = p
                while p.next and p.val == p.next.val:
                    p = p.next
                p = p.next
                pre.next = p
            else:
                p = p.next
        return head
```

## recurse
```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        if head.val == head.next.val:
            while head.next and head.val == head.next.val:
                head = head.next
        head.next = self.deleteDuplicates(head.next)
        return head
```

