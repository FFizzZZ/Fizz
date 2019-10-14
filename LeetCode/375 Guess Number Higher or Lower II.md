## Leetcode
#### Dynamic Programming
```
class Solution:
    def getMoneyAmount(self, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        for j in range(2, n + 1):
            for i in range(j - 1, 0, -1):
                if i + 1 == j:
                    dp[i][j] = i
                else:
                    Min = float("inf")
                    for mid in range((i + j) // 2, j):
                        tmp = max(dp[i][mid - 1], dp[mid + 1][j]) + mid
                        if tmp < Min: Min = tmp
                    dp[i][j] = Min
        return dp[1][n]
```


```
from functools import lru_cache
class Solution:
    def getMoneyAmount(self, n: int) -> int:
        @lru_cache(maxsize = None)
        def dp(i, j):
            if i >= j: return 0
            ans = float("inf")
            for mid in range((i + j) // 2, j + 1):
                left, right = dp(i, mid - 1), dp(mid + 1, j)
                tmp = mid + max(left, right)
                if tmp < ans: ans = tmp
                if left > right: break   # This one save lots of time!
            return ans
        return dp(1, n)    
```
