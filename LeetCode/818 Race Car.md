## Leetcode


#### Dynamic Programming
```
class Solution(object):
    def racecar(self, target):
        dp = [0] * (target + 1)
        for t in range(1, target + 1):
            k = t.bit_length()
            if 2 ** k - 1 == t:
                dp[t] = k
                continue
            val = float("inf")
            for i in range(k - 1):
                tmp = dp[t - 2 ** (k - 1) + 2 ** i] + k - 1 + i + 2
                if tmp < val: val = tmp
            dp[t] = val
            if 2 ** k - 1 - t < t:
                dp[t] = min(dp[t], dp[2 ** k - 1 - t] + k + 1)
        return dp[target]
```
