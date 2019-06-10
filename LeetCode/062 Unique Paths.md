```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        d = {}
        def move(i, j):
            if (i, j) in d: return d[(i, j)]
            if i == m and j == n:
                return 1
            else:
                ans = 0
                if i + 1 <= m:
                    ans += move(i+1, j)
                if j + 1 <= n:
                    ans += move(i, j+1)
                d[(i, j)] = ans
                return ans
        return move(1, 1)
```

## math
```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return int(math.factorial(m+n-2) / math.factorial(m-1) / math.factorial(n-1))
```

## dynamic programming
```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[1] * n for _ in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]
```
