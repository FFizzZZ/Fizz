## Leetcode
#### convert this one to the backpack problem
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

#### Something like BFS
```
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        s = sum(nums)
        if s < S or S < -s: return 0
        dp = [0] * (2 * s + 1)
        dp[s] = 1
        for i in nums:
            temp = [0] * (2 * s + 1)
            for j in range(2 * s + 1):
                if dp[j]:
                    temp[j + i] += dp[j]
                    temp[j - i] += dp[j]
            dp = temp
        return dp[s + S]
```
#### the same idea but using dict
```
class Solution(object):
    def findTargetSumWays(self, nums, S):
        from collections import defaultdict
        memo = {0: 1}
        for x in nums:
            m = defaultdict(int)
            for s, n in memo.items():
                m[s + x] += n
                m[s - x] += n
            memo = m
        return memo[S]
```
