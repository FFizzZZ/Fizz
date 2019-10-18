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
