## Leetcode
#### Dynamic Programming
```
class Solution:
    def maxCoins(self, iNums):
        num = [1] + [x for x in iNums if x > 0] + [1]
        n = len(num)
        dp = [[0] * n for _ in range(n)]
        for k in range(2, n):
            for left in range(n - k):
                right = left + k
                for i in range(left + 1, right):
                    temp = num[left] * num[i] * num[right] + dp[left][i] + dp[i][right]
                    if temp > dp[left][right]:
                        dp[left][right] = temp
        return dp[0][n - 1]
```

#### Recurse
```
class Solution:
    def maxCoins(self, iNums):
        nums = [1] + [x for x in iNums if x > 0] + [1]
        d = {}
        return self.f(0, len(nums) - 1, nums, d)
    def f(self, l, r, nums, d):
        if r == l + 1: return 0
        if (l, r) in d: return d[(l, r)]
        ans = 0
        for index in range(l + 1, r):
            temp = nums[l] * nums[index] * nums[r] + self.f(l, index, nums, d) + self.f(index, r, nums, d)
            if temp > ans:
                ans = temp
        d[(l, r)] = ans
        return ans
```
