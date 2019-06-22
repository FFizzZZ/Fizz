```
class Solution(object):
    def partition(self, head, x):
        q = node = ListNode(0)
        node.next = head
        temp = None
        while head:
            if head.val < x:
                if temp:
                    temp.next = head.next
                    head.next = q.next
                    q.next = head
                    q = head
                    head = temp.next
                else:
                    q.next = head
                    q = head
                    head = head.next
            else:
                temp = head
                head = head.next
        return node.next
```

## leetcode
```
class Solution(object):
    def partition(self, head, x):
        before = before_head = ListNode(0)
        after = after_head = ListNode(0)
        while head:
            if head.val < x:
                before.next = head
                before = before.next
            else:
                after.next = head
                after = after.next
            head = head.next
        after.next = None
        before.next = after_head.next
        return before_head.next
```
