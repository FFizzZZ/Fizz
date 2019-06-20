```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head: return None
        q = node = ListNode(0)
        node.next = head
        temp, p = head, head.next
        while p:
            if p.val == temp.val:
                while p and p.val == temp.val:
                    p = p.next
                if not p:
                    q.next = None
                    break
                else:
                    if p.next:
                        temp, p = p, p.next
                    else:
                        q.next = p     
                        break
            else:
                q.next = temp
                q = temp
                temp = p
                p = p.next              
        return node.next
```

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
