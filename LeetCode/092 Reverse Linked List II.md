## change the direction
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

```
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        p = node = ListNode(0)
        node.next = head
        for _ in range(m - 1):
            p = p.next
        last = self.f(p.next, n - m)
        last.next = self.r
        p.next = self.head
        return node.next
    def f(self, head, n):
        if n == 0:
            self.head = head
            self.r = head.next
            return head
        node = self.f(head.next, n - 1)
        node.next = head
        return head
```

## Leetcode Solution
## Insert nodes one by one
https://leetcode.com/problems/reverse-linked-list-ii/discuss/30709/Talk-is-cheap-show-me-the-code-(and-DRAWING)
```
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        pre = node = ListNode(0)
        node.next = head
        for _ in range(m-1):
            pre = pre.next
        start = pre.next
        then = start.next
        for _ in range(n - m):
            start.next = then.next
            then.next = pre.next
            pre.next = then
            then = start.next
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

