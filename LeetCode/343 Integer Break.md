```
class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2: return 1
        if n == 3: return 2
        dp = [i for i in range(n + 1)]
        for i in range(4, n + 1):
            ans = 0
            for j in range(2, i // 2 + 1):
                tmp = dp[i - j] * j
                if tmp > ans: ans = tmp
            dp[i] = ans
        return dp[n]
```
## Leetcode
```
class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[1] = 1
        for i in range(2, n + 1):
            for j in range(1, i // 2 + 1):
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]))
        return dp[-1]
```
#### Maybe the fastest method
##### for any x >= 4, we have 2 * (x - 2) >= x, so we won't have a factor greater than 4.
```
class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2: return 1
        if n == 3: return 2
        ans = 1
        while n > 4:
            ans *= 3
            n -= 3
        return n * ans
```


