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


#### Compare one by one
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

#### Merge with Divide And Conquer
```
class Solution(object):
    def mergeKLists(self, lists):
        if not lists: return None
        if len(lists) == 1: return lists[0]
        n = len(lists)
        left = self.mergeKLists(lists[:n//2])
        right = self.mergeKLists(lists[n//2:])
        return self.merge2Lists(left, right)


    def merge2Lists(self, l1, l2):
        head = point = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                point.next = l1
                l1 = l1.next
            else:
                point.next = l2
                l2 = l1
                l1 = point.next.next
            point = point.next
        point.next = l1 or l2
        return head.next
```
