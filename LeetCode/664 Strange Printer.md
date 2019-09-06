## Leetcode
```
class Solution:
    def strangePrinter(self, S):
        if not S: return 0
        n = len(S)
        dp = [[0] * n for _ in range(n)]
        for j in range(n):
            for i in range(j, -1, -1):
                if i == j:
                    dp[i][j] = 1
                elif i + 1 == j:
                    dp[i][j] = 1 + int(S[i] != S[j])
                else:
                    tmp = 1 + dp[i + 1][j]
                    if S[i] == S[j]: tmp = min(tmp, dp[i][j - 1])
                    for k in range(i + 1, j):
                        if S[k] == S[i]:
                            val = dp[i][k - 1] + dp[k + 1][j]
                            if val < tmp:
                                tmp = val
                    dp[i][j] = tmp
        return dp[0][-1]
```
