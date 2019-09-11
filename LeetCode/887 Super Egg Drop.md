## Leetcode
#### Dynamic Programming
```
class Solution(object):
    def superEggDrop(self, K, N):
        memo = {}
        def dp(k, n):
            if (k, n) not in memo:
                if n == 0:
                    ans = 0
                elif k == 1:
                    ans = n
                else:
                    lo, hi = 1, n
                    while lo + 1 < hi:
                        x = (lo + hi) // 2
                        t1 = dp(k-1, x-1)
                        t2 = dp(k, n-x)
                        if t1 < t2:
                            lo = x
                        elif t1 > t2:
                            hi = x
                        else:
                            lo = hi = x
                    ans = 1 + min(max(dp(k-1, x-1), dp(k, n-x)) for x in (lo, hi))
                memo[k, n] = ans
            return memo[k, n]
        return dp(K, N)
```
####### TLE
```
class Solution(object):
    def superEggDrop(self, K, N):
        dp = [[0] * (K + 1) for _ in range(N + 1)]
        for i in range(1, N + 1):
            for j in range(1, K + 1):
                if j == 1:
                    dp[i][j] = i
                else:
                    l, r = 1, i
                    while l + 1 < r:
                        mid = (l + r) // 2
                        t1 = dp[mid - 1][j - 1]
                        t2 = dp[i - mid][j]
                        if t1 < t2:
                            l = mid
                        elif t1 > t2:
                            r = mid
                        else:
                            l = r = mid
                    dp[i][j] = 1 + min(max(dp[x - 1][j - 1], dp[i - x][j]) for x in (l, r))
        return dp[N][K]
```
#### Another Great Idea
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
