## Leetcode
```
class Solution:
    def new21Game(self, N: int, K: int, W: int) -> float:
        dp = [0] * max(N + 1, K + W + 1)
        for i in range(K, N + 1):
            dp[i] = 1
        s = min(N - K + 1, W)
        for i in range(K - 1, -1, -1):
            dp[i] = s / W
            s += dp[i] - dp[i + W]
        return dp[0]
```
