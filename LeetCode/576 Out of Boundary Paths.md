```
from functools import lru_cache
class Solution:
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        @lru_cache(maxsize = None)
        def dfs(x, y, times):
            if x == -1 or x == m or y == -1 or y == n:
                return 1
            if times == 0: return 0
            times -= 1
            return dfs(x, y + 1, times) + dfs(x, y - 1, times) + dfs(x + 1, y, times) + \
                    dfs(x - 1, y, times)
        return dfs(i, j, N) % (10 ** 9 + 7)
```
