## Leetcode
#### Recurse
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
#### Iteration
```
class Solution(object):
    def sortList(self, head):
        if not head or not head.next: return head
        cur = head
        l = 0
        while cur:
            l += 1
            cur = cur.next
        dummy = ListNode(0)
        dummy.next = head
        step = 1
        while step < l:
            cur = dummy.next
            tail = dummy
            while cur:
                left = cur
                right = self.split(left, step)
                cur = self.split(right, step)
                tail = self.merge(left, right, tail)
            step <<= 1
        return dummy.next
    def split(self, head, n):
        i = 1
        while head and i < n:
            head = head.next
            i += 1
        if not head: return None
        second = head.next
        head.next = None
        return second
    def merge(self, left, right, tail):
        cur = tail
        while left and right:
            if left.val < right.val:
                cur.next = left
                left = left.next
            else:
                cur.next = right
                right = right.next
            cur = cur.next
        if right:
            cur.next = right
        if left:
            cur.next = left
        while cur.next:
            cur = cur.next
        return cur
```
