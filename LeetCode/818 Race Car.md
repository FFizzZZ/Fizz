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

##### Fastest
```
class Solution:
    dp = {0: 0}
    def racecar(self, target: int) -> int:
        if target in self.dp:
            return self.dp[target]
        n = target.bit_length()
        if 2 ** n - 1 == target:
            self.dp[target] = n
        else:
            self.dp[target] = self.racecar(2 ** n - 1 - target) + n + 1
            for m in range(n - 1):
                self.dp[target] = min(self.dp[target], self.racecar(target - 2 ** (n - 1) + 2 ** m) + n + m + 1)
        return self.dp[target]
```
