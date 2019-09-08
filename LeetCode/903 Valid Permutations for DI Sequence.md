## Leetcode
#### Dynamic Programming
```
class Solution:
    def numPermsDISequence(self, S: str) -> int:
        n = len(S)
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        for j in range(n + 1):
            dp[0][j] = 1
        for i in range(n):
            cur = 0
            if S[i] == 'I':
                for j in range(n - i):
                    cur += dp[i][j]
                    dp[i + 1][j] = cur
            else:
                for j in range(n - i - 1, -1, -1):
                    cur += dp[i][j + 1]
                    dp[i + 1][j] = cur
        return dp[n][0] % (10 ** 9 + 7)
```

##### Optimized Version
```
class Solution:
    def numPermsDISequence(self, S: str) -> int:
        n = len(S)
        dp = [1] * (n + 1)
        for char in S:
            if char == 'I':
                dp = dp[:-1]
                for i in range(1, len(dp)):
                    dp[i] += dp[i - 1]
            else:
                dp = dp[1:]
                for i in range(len(dp) - 2, -1, -1):
                    dp[i] += dp[i + 1]
        return dp[0] % (10 ** 9 + 7)
```
                
                
                
                
    
