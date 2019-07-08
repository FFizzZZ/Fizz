
## Leetcode

```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        slow, fast = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        if fast:
            slow = slow.next
        l, r = head, self.reverse(slow)
        while l and r:
            if l.val != r.val:
                return False
            l = l.next
            r = r.next
        return True
    def reverse(self, head):
        pre = None
        while head:
            temp = head.next
            head.next = pre
            pre = head
            head = temp
        return pre
```
