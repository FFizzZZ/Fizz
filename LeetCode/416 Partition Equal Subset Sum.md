## Leetcode
#### dynamic programming
```
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if s & 1: return False
        n = len(nums)
        s //= 2
        dp = [False] * (s + 1)
        dp[0] = True
        for i in range(1, n + 1):
            for j in range(s, 0, -1):
                dp[j] = dp[j] or nums[i - 1] <= j and dp[j - nums[i - 1]]
        return dp[-1]
```
###### Similar to Coin Changes, here we can use nums in the outter loop
```
class Solution(object):
    def canPartition(self, nums):
        sum_val = sum(nums)
        if sum_val % 2 == 1:
            return False
        target = sum_val // 2
        dp = [False] * (sum_val + 1)
        dp[0] = True
        for num in nums:
            next_dp = [False] * (sum_val + 1)
            for j in range(len(dp)):
                if dp[j]:
                    next_dp[j + num] = True
                    next_dp[j] = True
            dp = next_dp
        return dp[target]
```
###### Finally, we get a optimized version using bits. It's really amazing!
```
class Solution(object):
    def canPartition(self, nums):
        s = 0
        bit = 1
        for num in nums:
            s += num
            bit |= bit << num
        return s & 1 == 0 and (bit >> (s // 2)) & 1 == 1
```
