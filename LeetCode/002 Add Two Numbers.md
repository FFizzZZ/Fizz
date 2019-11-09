```
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num = self.transfer(l1) + self.transfer(l2)
        node = head = ListNode(0)
        if num == 0: return head
        while num:
            num, r = divmod(num, 10)
            node.next = ListNode(r)
            node = node.next
        return head.next
        
    def transfer(self, node):
        ans = 0
        m = 1
        while node:
            ans += m * node.val
            m *= 10
            node = node.next
        return ans
```
## Leetcode
```
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        node = head = ListNode(0)
        carry = 0
        while l1 or l2:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            val = x + y + carry
            carry, val = divmod(val, 10)
            node.next = ListNode(val)
            node = node.next
            if l1: l1 = l1.next
            if l2: l2 = l2.next
        if carry:
            node.next = ListNode(1)
        return head.next
```
