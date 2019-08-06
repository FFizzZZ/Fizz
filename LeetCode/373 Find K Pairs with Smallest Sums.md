## Leetcode
```
from queue import PriorityQueue
class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        if not nums1 or not nums2 or k == 0: return []        
        q = PriorityQueue()
        n1, n2 = len(nums1), len(nums2)
        ans = []
        for i in range(min(n1, k)):
            q.put([nums1[i] + nums2[0], nums2[0], 0])
        for _ in range(k):
            if q.empty(): break
            val1, val2, row = q.get()
            ans.append([val1 - val2, val2])
            if row == n2 - 1: continue
            q.put([val1 - val2 + nums2[row + 1], nums2[row + 1], row + 1])
        return ans
```

```
class Solution:
    def kSmallestPairs(self, nums1, nums2, k):
        queue = []
        n1, n2 = len(nums1), len(nums2)
        def push(i, j):
            if i < n1 and j < n2:
                heapq.heappush(queue, [nums1[i] + nums2[j], i, j])
        push(0, 0)
        ans = []
        cnt = 0
        while queue and cnt < k:
            _, i, j = heapq.heappop(queue)
            ans.append([nums1[i], nums2[j]])
            cnt += 1
            push(i, j + 1)
            if j == 0:
                push(i + 1, j)
        return ans
```
