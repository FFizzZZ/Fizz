## Leetcode
```
class Solution:
    def findRotateSteps(self, ring, key):
        pos = collections.defaultdict(list)
        for idx, char in enumerate(ring):
            pos[char].append(idx)
        dp = {0: 0}
        def dist(i, j):
            return min(abs(i - j), len(ring) - abs(i - j))
        for char in key:
            new_dp = {}
            for cur in pos[char]:
                new_dp[cur] = float("inf")
                for pre in dp:
                    new_dp[cur] = min(new_dp[cur], dp[pre] + dist(pre, cur))
            dp = new_dp
        return min(dp.values()) + len(key)
```

#### FASTER
```
from functools import lru_cache
class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        m, n = len(key), len(ring)
        @lru_cache(maxsize = None)
        def dfs(ring, idx):
            if idx == m: return 0
            target = key[idx]
            if ring[0] == target:
                return dfs(ring, idx + 1)
            anti = ring.find(target)
            ans_anti = anti + dfs(ring[anti:] + ring[:anti], idx + 1)
            clock = ring.rfind(target)
            ans_clk = n - clock + dfs(ring[clock:] + ring[:clock], idx + 1)
            return min(ans_anti, ans_clk)
        return dfs(ring, 0) + m
```
