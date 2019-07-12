## Leetcode
```
class Solution:
    def topKFrequent(self, nums, k):
        count = collections.Counter(nums)   
        return heapq.nlargest(k, count.keys(), key=count.get) 
```
