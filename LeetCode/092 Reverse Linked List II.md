```
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        start = node = ListNode(0)
        node.next = head
        for _ in range(m-1):
            node = node.next
        pre = None
        p = q = node.next
        for _ in range(n-m+1):
            temp = p.next
            p.next = pre
            pre = p
            p = temp
        node.next = pre
        q.next = p
        return start.next
```

## https://leetcode.com/problems/reverse-linked-list-ii/discuss/30709/Talk-is-cheap-show-me-the-code-(and-DRAWING)
```
class Solution(object):
    def reverseBetween(self, head, m, n):
        if m == n: return head
        node = ListNode(0)
        node.next = head
        start, tail = node, node
        for i in range(m-1):
            start = start.next
            tail = tail.next
        tail = tail.next
        for i in range(n-m):
            temp = start.next
            start.next = tail.next
            tail.next = tail.next.next
            start.next.next = temp
        return node.next
```

## Recursive
```
class Solution:
    def reverseBetween(self, head, m, n):
        if not head:
            return None
        left, right = head, head
        stop = False
        def recurseAndReverse(right, m, n):
            nonlocal left, stop
            if n == 1:
                return
            right = right.next
            if m > 1:
                left = left.next
            recurseAndReverse(right, m - 1, n - 1)
            if left == right or right.next == left:
                stop = True
            if not stop:
                left.val, right.val = right.val, left.val
                left = left.next           
        recurseAndReverse(right, m, n)
        return head
```
