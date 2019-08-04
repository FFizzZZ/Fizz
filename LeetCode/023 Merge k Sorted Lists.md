## Leetcode

#### Brute Force
```
class Solution(object):
    def mergeKLists(self, lists):
        vals = []
        head = node = ListNode(0)
        for x in lists:
            while x:
                vals.append(x.val)
                x = x.next
        vals.sort()
        for val in vals:
            node.next = ListNode(val)
            node = node.next
        return head.next
```
