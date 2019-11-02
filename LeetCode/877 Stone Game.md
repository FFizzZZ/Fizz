```
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        return self.f(0, len(piles) - 1, piles, {}) > 0
    def f(self, l, r, piles, d):
        if l > r: return 0
        if (l, r) in d: return d[(l, r)]
        a = piles[l] - self.f(l + 1, r, piles, d)
        b = piles[r] - self.f(l, r - 1, piles, d)
        ans = max(a, b)
        d[(l, r)] = ans
        return ans
```

## Leetcode
```
from functools import lru_cache
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        @lru_cache(None)
        def f(l, r):
            if l > r: return 0
            a = piles[l] - f(l + 1, r)
            b = piles[r] - f(l, r - 1)
            ans = max(a, b)
            return ans
        return f(0, len(piles) - 1) > 0
```

```
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [[0] * n for _ in range(n)]
        for d in range(n):
            for i in range(n - d):
                if d == 0:
                    dp[i][i + d] = piles[i]
                else:
                    dp[i][i + d] = max(piles[i] - dp[i + 1][i + d], piles[i + d] - dp[i][i + d - 1])
        return dp[0][-1]
```

```
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [[0] * n for _ in range(n)]
        for j in range(n):
            for i in range(j, -1, -1):
                if i == j:
                    dp[i][j] = piles[i]
                else:
                    dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])
        return True if dp[0][-1] else False
```
#### Math
```
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        return True
```


