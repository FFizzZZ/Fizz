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
