
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
#### Reverse the first half while finding the middle
```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        pre = None
        slow, fast = head, head
        while fast and fast.next:
            fast = fast.next.next
            pre, pre.next, slow = slow, pre, slow.next
        if fast:
            slow = slow.next
        while pre and pre.val == slow.val:
            slow = slow.next
            pre = pre.next
        return not pre
```

#### This one recovers the linked list
```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        pre = None
        slow, fast = head, head
        while fast and fast.next:
            fast = fast.next.next
            pre, pre.next, slow = slow, pre, slow.next
        node = slow
        if fast:
            slow = slow.next
        ans = True
        while pre:
            ans = ans and pre.val == slow.val
            slow = slow.next
            pre.next, pre, node = node, pre.next, pre
        return ans
```
