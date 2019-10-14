## Leetcode
#### Dynamic Programming
```
class Solution:
    def getMoneyAmount(self, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        for j in range(2, n + 1):
            for i in range(j - 1, 0, -1):
                if i == j - 1:
                    dp[i][j] = i
                else:
                    Min = float("inf")
                    for k in range(i + 1, j):
                        tmp = k + max(dp[i][k - 1], dp[k + 1][j])
                        if tmp < Min: Min = tmp
                    dp[i][j] = Min
        return dp[1][n]
```
