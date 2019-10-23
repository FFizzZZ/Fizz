## Leetcode
```
class Solution(object):
    def new21Game(self, N, K, W):
        dp = [0.0] * (K + W + 1)
        # dp[x] = the answer when Alice has x points
        for k in range(K, N + 1):
            dp[k] = 1.0
        S = min(N - K + 1, W)
        for k in range(K - 1, -1, -1):
            dp[k] = S / W
            S += dp[k] - dp[k + W]
        return dp[0]
```
