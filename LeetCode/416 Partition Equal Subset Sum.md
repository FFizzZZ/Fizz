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
