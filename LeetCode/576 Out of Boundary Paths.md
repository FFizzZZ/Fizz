```
from functools import lru_cache
class Solution:
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        visited = set()
        @lru_cache(maxsize = None)
        def dfs(x, y, times):
            if x in [-1, m] or y in [-1, n]:
                return 1
            ans = 0
            if times == 0: return ans
            for i, j in [(x, y + 1), (x, y - 1), (x + 1, y), (x - 1, y)]:
                    ans += dfs(i, j, times - 1)
            return ans
        return dfs(i, j, N) % (10 ** 9 + 7)
```

## Leetcode
```
from functools import lru_cache
class Solution:
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        @lru_cache(None)
        def move(i, j, N):
            if i < 0 or i >= m or j < 0 or j >= n:
                return 1
            if N == 0:
                return 0 
            return move(i + 1, j, N-1) + \
                   move(i - 1, j, N-1) + \
                   move(i, j + 1, N-1) + \
                   move(i, j - 1, N-1)
        return move(i, j, N) % (10 ** 9 + 7)
```
