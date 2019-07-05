## Leetcode
```
class Solution(object):
    def sortList(self, head):
        if not head or not head.next: return head
        pre, slow, fast = None, head, head
        while fast and fast.next:
            pre = slow
            slow = slow.next
            fast = fast.next.next
        pre.next = None
        left = self.sortList(head)
        right = self.sortList(slow)
        return self.merge(left, right)
    def merge(self, left, right):
        node = dummy = ListNode(0)
        while left and right:
            if left.val < right.val:
                node.next = left
                left = left.next
            else:
                node.next = right
                right = right.next
            node = node.next
        if left:
            node.next = left
        if right:
            node.next = right
        return dummy.next
```
