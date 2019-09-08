## Leetcode

#### Dynamic Programming
```
class Solution:
    def numMusicPlaylists(self, N, L, K):
        dp = [[0] * (L + 1) for _ in range(N + 1)]
        dp[0][0] = 1
        for i in range(1, N + 1):
            for j in range(i, L + 1):
                dp[i][j] = dp[i - 1][j - 1] * i + dp[i][j - 1] * max(i - K, 0)
        return dp[N][L] % (10 ** 9 + 7)
```

#### Optimized Version
```
class Solution:
    def numMusicPlaylists(self, N, L, K):
        dp = [[0] * (L + 1) for _ in range(N + 1)]
        for i in range(K + 1, N + 1):
            for j in range(i, L + 1):
                if i == K + 1:
                    dp[K + 1][j] = math.factorial(K + 1)
                else:
                    dp[i][j] = dp[i - 1][j - 1] * i + dp[i][j - 1] * (i - K)
        return dp[N][L] % (10 ** 9 + 7)
```
#### Space Optimization
```
class Solution:
    def numMusicPlaylists(self, N, L, K):
        pre = [math.factorial(K + 1)] * (L + 1)
        for i in range(K + 2, N + 1):
            cur = [0] * (L + 1)
            for j in range(i, L + 1):
                cur[j] = pre[j - 1] * i + cur[j - 1] * (i - K)
            pre = cur[:]
        return pre[-1] % (10 ** 9 + 7)
```
