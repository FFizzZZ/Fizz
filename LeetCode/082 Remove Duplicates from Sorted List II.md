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
