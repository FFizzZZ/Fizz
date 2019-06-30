```
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        ls, lt = len(s), len(t)
        dp = [0] * (lt + 1)
        dp[0] = 1
        for i in range(1, ls + 1):
            for j in range(min(i, lt), 0, -1):
                if s[i - 1] == t[j - 1]:
                    dp[j] = dp[j] + dp[j - 1]
        return dp[-1]
```
