## Leetcode

#### Dynamic Programming
```
class Solution:
    def distinctSubseqII(self, S: str) -> int:
        last = dict()
        dp = [1] * (len(S) + 1)
        for idx, char in enumerate(S):
            val = dp[idx] * 2
            if char in last:
                val -= dp[last[char]]
            dp[idx + 1] = val
            last[char] = idx
        return (dp[-1] - 1) % (10 ** 9 + 7)
```
###### Optimized Version
```
class Solution:
    def distinctSubseqII(self, S: str) -> int:
        ans = 1
        M = 10 ** 9 + 7
        d = collections.defaultdict(int)
        for char in S:
            tmp = ans
            ans += ans - d[char]
            ans %= M
            d[char] = tmp
        return ans - 1
```
