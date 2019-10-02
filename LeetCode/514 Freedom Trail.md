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
