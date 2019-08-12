## Leetcode
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
