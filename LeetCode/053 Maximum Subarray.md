```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = cur = float("-inf")
        for x in nums:
            if cur < 0:
                cur = x
            else:
                cur += x
            if cur > ans: ans = cur
        return ans
```

## Leetcode
```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            if nums[i-1] > 0:
                nums[i] += nums[i-1]
        return max(nums)
```

       
