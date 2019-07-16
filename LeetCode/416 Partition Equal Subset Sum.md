## Leetcode
#### dynamic programming
###### Something like backpack problem, dp[i][j] means whether we can reach j by first i items
```
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if s & 1: return False
        n = len(nums)
        s //= 2
        dp = [False] * (s + 1)
        dp[0] = True
        for num in nums:
            for j in range(s, num - 1, -1):
                dp[j] = dp[j] or dp[j - num]
        return dp[-1]
```
###### Another version
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
