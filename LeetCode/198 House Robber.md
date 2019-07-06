#### Recurse
```
class Solution(object):
    def rob(self, nums):
        d = {}
        return self.f(0, nums, d)
    def f(self, i, nums, d):
        if i >= len(nums):
            return 0
        if i in d: return d[i]
        val1 = nums[i] + self.f(i + 2, nums, d)
        val2 = nums[i + 1] + self.f(i + 3, nums, d) if i + 1 < len(nums) else 0
        ans = val1 if val1 > val2 else val2
        d[i] = ans
        return ans
```
#### Dynamic Programming
```
class Solution(object):
    def rob(self, nums):
        if not nums: return 0
        n = len(nums)
        dp = [0] * (n + 1)
        dp[1] = nums[0]
        for i in range(2, n + 1):
            dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1])
        return dp[-1]
```
#### Optimized Version
```
class Solution(object):
    def rob(self, nums):
        if not nums: return 0
        n = len(nums)
        first, second = 0, nums[0]
        for i in range(2, n + 1):
            first, second = second, max(nums[i - 1] + first, second)
        return second
```

## Leetcode
I think it is like DP
```
class Solution(object):
    def rob(self, nums):
        a, b = 0, 0
        for i in nums:
            a, b = b, max(a + i, b)
        return b
```
