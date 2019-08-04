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

```
from queue import PriorityQueue
class Solution(object):
    def mergeKLists(self, lists):
        head = point = ListNode(0)
        q = PriorityQueue()
        n = 0
        for l in lists:
            if l:
                q.put([l.val, n, l])
                n += 1
        while not q.empty():
            val, _, node = q.get()
            point.next = ListNode(val)
            point = point.next
            node = node.next
            if node:
                q.put([node.val, n, node])
                n += 1
        return head.next 
```
