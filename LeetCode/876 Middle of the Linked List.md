```
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if not head.next: return head
        if not head.next.next: return head.next
        fast = slow = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        if not fast.next:
            return slow
        else:
            return slow.next
```

## Leetcode
```
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
```
