## Leetcode
#### Heap TLE!
```
class Solution(object):
    def smallestDistancePair(self, nums, k):
        nums.sort()
        n = len(nums)
        heap = [(nums[i + 1] - nums[i], i, i + 1) for i in range(n - 1)]
        heapq.heapify(heap)
        
        for _ in range(k):
            diff, root, nei = heapq.heappop(heap)
            if nei + 1 < n:
                heapq.heappush(heap, (nums[nei + 1] - nums[root], root, nei + 1))    
        return diff
```


#### Binary Search
```
class Solution(object):
    def smallestDistancePair(self, nums, k):
        nums.sort()
        l, r = 0, nums[-1] - nums[0]
        while l < r:
            mid = (l + r) // 2
            if self.check(mid, nums, k):
                r = mid
            else:
                l = mid + 1
        return l
    def check(self, val, nums, k):
        cnt = left = 0
        for right, value in enumerate(nums):
            while value - nums[left] > val:
                left += 1
            cnt += right - left
        return cnt >= k
```
