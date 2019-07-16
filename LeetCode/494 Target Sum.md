## Leetcode
```
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        s = sum(nums)
        if s < S or (s + S) & 1:
            return 0
        else:
            return self.f(nums, (s + S) >> 1)
    def f(self, nums, target):
        dp = [0] * (target + 1)
        dp[0] = 1
        for i in nums:
            for j in range(target, i - 1, -1):
                dp[j] += dp[j - i]
        return dp[-1]
```
```
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        s = sum(nums)
        if s < S or (s + S) & 1:
            return 0
        else:
            return self.f(nums, (s + S) >> 1)
    def f(self, nums, target):
        dp = [0] * (target + 1)
        dp[0] = 1
        for i in nums:
            temp = dp.copy()
            for j in range(target - i + 1):
                if dp[j]:
                    temp[j + i] += dp[j]
            dp = temp
        return dp[-1]
```
