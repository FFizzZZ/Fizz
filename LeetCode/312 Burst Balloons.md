## Leetcode
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
