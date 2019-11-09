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
    def addTwoNumbers(self, l1: 'ListNode', l2: 'ListNode') -> 'ListNode':
        head = ListNode(0)
        ptr = head
        t = 0
        while True:
            if l1 != None:
                t += l1.val
                l1 = l1.next
            if l2 != None:
                t += l2.val
                l2 = l2.next
            ptr.val = t % 10
            t //= 10
            if l1 != None or l2 != None or t != 0:
                ptr.next = ListNode(0)
                ptr = ptr.next
            else:
                break
        return head
```
