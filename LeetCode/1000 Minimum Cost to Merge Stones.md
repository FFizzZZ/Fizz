## Leetcode
#### dp(i, k, m) means the minimum cost to merge stones[i] - stones[j] into m piles
```
import functools
class Solution:
    def mergeStones(self, stones, K):
        n = len(stones)
        if (n - 1) % (K - 1): return -1
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stones[i]
        inf = float("inf")
        
        @functools.lru_cache(None)
        def dp(i, j, m):
            if i == j:
                return 0 if m == 1 else inf
            if m == 1:
                return dp(i, j, K) + prefix[j + 1] - prefix[i]
            return min(dp(i, mid, 1) + dp(mid + 1, j, m - 1) for mid in range(i, j, K - 1))
        ans = dp(0, n - 1, 1)
        return ans
```
#### dp(i, j) means the minimum cost needed to merge stones[i] - stones[j]
```
import functools
class Solution:
    def mergeStones(self, stones, K):
        n = len(stones)
        if (n - 1) % (K - 1): return -1
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stones[i]
        import functools
        @functools.lru_cache(None)
        def dp(i, j):
            if i == j: return 0
            res = min(dp(i, mid) + dp(mid + 1, j) for mid in range(i, j, K - 1))
            if (j - i) % (K - 1) == 0:
                res += prefix[j + 1] - prefix[i]
            return res
        return dp(0, n - 1)
```
###### Bottom-up Version
```
class Solution:
    def mergeStones(self, stones, K):
        n = len(stones)
        if (n - 1) % (K - 1): return -1
        inf = float('inf')
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + stones[i]

        dp = [[0] * n for _ in range(n)]
        for m in range(K, n + 1):
            for i in range(n - m + 1):
                j = i + m - 1
                dp[i][j] = inf
                for mid in range(i, j, K - 1):
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j])
                if (j - i) % (K - 1) == 0:
                    dp[i][j] += prefix[j + 1] - prefix[i]
        return dp[0][n - 1]
```

###### Here I want to write down some thoughts about this transition equation.
###### The first part should be booled down to one plie, and two part adding together would not be larger than K.
###### Very Important!
