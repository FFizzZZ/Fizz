## Leetcode
#### Heap
```
class Solution(object):
    def mergeKLists(self, lists):
        heap = []
        for idx, node in enumerate(lists):
            if node:
                heapq.heappush(heap, [node.val, idx])
        head = pre = ListNode(0)
        while heap:
            val, idx = heapq.heappop(heap)
            node = lists[idx]
            pre.next = node
            pre = node
            if node.next:
                heapq.heappush(heap, [node.next.val, idx])
                lists[idx] = node.next
        return head.next
```

#### Merge with Divide And Conquer
###### recursive version
```
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists: return None
        if len(lists) == 1: return lists[0]
        left = self.mergeKLists(lists[:len(lists) // 2])
        right = self.mergeKLists(lists[len(lists) // 2:])
        return self.merge2Lists(left, right)
    
    def merge2Lists(self, l1, l2):
        pre = head = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                pre.next = l1
                l1 = l1.next
            else:
                pre.next = l2
                l2 = l2.next
            pre = pre.next
        pre.next = l1 or l2
        return head.next
```

###### iterative version
```
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        amount = len(lists)
        if amount == 0: return None
        interval = 1
        while interval < amount:
            for i in range(0, amount - interval, interval * 2):
                lists[i] = self.merge2Lists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0]
    
    def merge2Lists(self, l1, l2):
        pre = head = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                pre.next = l1
                l1 = l1.next
            else:
                pre.next = l2
                l2 = l2.next
            pre = pre.next
        pre.next = l1 or l2
        return head.next
```
