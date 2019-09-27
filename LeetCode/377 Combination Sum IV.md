```
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target + 1)
        dp[0] = 1
        for j in range(target + 1):
            for x in nums:
                if j - x >= 0:
                    dp[j] += dp[j - x] 
        return dp[-1]
```
