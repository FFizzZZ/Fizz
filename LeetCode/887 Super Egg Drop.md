## Leetcode
#### dp[i][j] means the number of floors we can check by i moves and j eggs
```
class Solution(object):
    def superEggDrop(self, K, N):
        dp = [[0] * (K + 1) for i in range(N + 1)]
        for i in range(1, N + 1):
            for j in range(1, K + 1):
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + 1
            if dp[i][K] >= N: return i
```
##### Optimized Version
```
class Solution(object):
    def superEggDrop(self, K, N):
        dp = [0] * (K + 1)
        for i in range(1, N + 1):
            for j in range(K, 0, -1):
                dp[j] += dp[j - 1] + 1
            if dp[K] >= N: return i
```
