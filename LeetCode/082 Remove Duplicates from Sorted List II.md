## iteration
```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        node = ListNode(0)
        node.next = head
        pre, cur = node, head
        while cur and cur.next:
            if cur.val == cur.next.val:
                while cur.next and cur.val == cur.next.val:
                    cur = cur.next
                cur = cur.next
                pre.next = cur
            else:
                pre = cur
                cur = cur.next
        return node.next
```

## recurse
```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        if head.val == head.next.val:
            while head.next and head.val == head.next.val:
                head = head.next
            return self.deleteDuplicates(head.next)
        else:
            head.next = self.deleteDuplicates(head.next)
            return head
```
