```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = nums[0]
        pre = 0
        for i in range(len(nums)):
            if pre < 0:
                pre = nums[i]
            else:
                pre += nums[i]
            if pre > ans:      # Here I compare the speed of 'ans = max(ans, pre)' and 'if pre > ans:....',
                ans = pre      # I found that the second one is faster.
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
        


```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [nums[0]]
        for i in range(1, n):
            if dp[i - 1] < 0:
                dp.append(nums[i])
            else:
                dp.append(dp[i - 1] + nums[i])
        return max(dp)
```

       
