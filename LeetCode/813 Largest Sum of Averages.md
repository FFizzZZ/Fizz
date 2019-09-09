## Leetcode
#### Dynamic Programming
```
import functools
class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        n = len(A)
        p = [0] * (n + 1)
        for i in range(n):
            p[i + 1] = p[i] + A[i]
        @functools.lru_cache(None)
        def dfs(start, k):
            if k == 1:
                return (p[n] - p[start]) / (n - start)
            ans = float('-inf')
            for i in range(start + 1, n + 2 - k):
                tmp = (p[i] - p[start]) / (i - start) + dfs(i, k - 1)
                if tmp > ans:
                    ans = tmp
            return ans
        return dfs(0, K)
```
```
class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        n = len(A)
        p = [0] * (n + 1)
        for i in range(n):
            p[i + 1] = p[i] + A[i]
        dp = [[0] * (K + 1) for _ in range(n + 1)]
        for k in range(1, K + 1):
            for i in range(n - 1, -1, -1):
                if k == 1:
                    dp[i][k] = (p[n] - p[i]) / (n - i)
                else:
                    res = -1
                    for j in range(i + 1, n + 2 - k):
                        tmp = (p[j] - p[i]) / (j - i) + dp[j][k - 1]
                        if tmp > res:
                            res = tmp
                    dp[i][k] = res
        return dp[0][K]
```
