## Leetcode
```
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        return self.f(nums, 0, len(nums) - 1, {}) >= 0
    def f(self, nums, l, r, d):
        if l == r:
            return nums[l]
        if (l, r) in d:
            return d[(l, r)]
        a = nums[l] - self.f(nums, l + 1, r, d)
        b = nums[r] - self.f(nums, l, r - 1, d)
        val = max(a, b)
        d[(l, r)] = val
        return val
```

#### Dynamic Programming 2D
```
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        l = len(nums)
        dp = [[0] * l for _ in range(l)]
        for i in range(l - 2, -1, -1):
            for j in range(i + 1, l):
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])
        return dp[0][-1] >= 0
```
#### dp 1D
```
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        l = len(nums)
        dp = [0] * l
        for i in range(l - 2, -1, -1):
            for j in range(i + 1, l):
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1])
        return dp[-1] >= 0
```
