## Leetcode
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
