## Leetcode
#### Dynamic Programming
```
class Solution:
    def numTilings(self, N: int) -> int:
        if N == 1: return 1
        M = 10 ** 9 + 7
        dp = [1] * (N + 1)
        dp[2] = 2
        for i in range(3, N + 1):
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % M
        return dp[-1]
```
###### Optimized Version
```
class Solution:
    def numTilings(self, N: int) -> int:
        if N == 1: return 1
        M = 10 ** 9 + 7
        first, second, third = 1, 1, 2
        for _ in range(3, N + 1):
            first, second, third = second, third, (2 * third + first) % M
        return third
```

dp[n] = dp[n-1] + dp[n-2] + 2 * (dp[n-3] + ... + d[0])  
= dp[n-1]+ dp[n-2] + dp[n-3] + dp[n-3] + 2 * (dp[n-4] + ... + d[0])  
= dp[n-1] + dp[n-3] + (dp[n-2] + dp[n-3] + 2 * (dp[n-4] + ... + d[0]))  
= dp[n-1] + dp[n-3] + dp[n-1]
= 2 * dp[n-1] + dp[n-3]
