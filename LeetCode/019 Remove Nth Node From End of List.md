```
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        pre = dummy = ListNode(0)
        pre.next = head
        first = second = head
        while n:
            second = second.next
            n -= 1
        while second:
            pre = first
            first = first.next
            second = second.next
        pre.next = first.next
        return dummy.next
```

## Leetcode
```
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        first = second = dummy
        for _ in range(n + 1):
            first = first.next
        while first:
            first = first.next
            second = second.next
        second.next = second.next.next
        return dummy.next
```



