```
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        ls, lt = len(s), len(t)
        dp = [0] * (lt + 1)
        dp[0] = 1
        for i in range(1, ls + 1):
            for j in range(min(i, lt), 0, -1):
                if s[i - 1] == t[j - 1]:
                    dp[j] = dp[j] + dp[j - 1]
        return dp[-1]
```
## Leetcode
```
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        dp = [1] + [0] * len(t)
        indices = collections.defaultdict(list)
        for i, c in reversed(list(enumerate(t))):
            indices[c].append(i + 1)
        for c in s:
            for i in indices[c]:
                    dp[i] += dp[i - 1]
        return dp[-1]
```
