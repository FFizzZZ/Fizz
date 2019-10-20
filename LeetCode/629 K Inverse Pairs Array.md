## Leetcode
```
class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        dp = [[1] * (k + 1) for _ in range(n + 1)]
        M = 10 ** 9 + 7
        for i in range(1, n + 1):
            for j in range(k + 1):
                if j == 0:
                    dp[i][j] = 1
                else:
                    val = dp[i - 1][j]
                    if j - i >= 0: val -= dp[i - 1][j - i]
                    dp[i][j] = (dp[i][j - 1] + val) % M
        print(dp)
        return (dp[n][k] - (dp[n][k - 1] if k - 1 >= 0 else 0)) % M
```

```
class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        M = 10 ** 9 + 7
        for i in range(1, n + 1):
            Max = i * (i - 1) // 2
            for j in range(k + 1):
                if j == 0:
                    dp[i][j] = 1
                else:
                    val = dp[i - 1][j] - (dp[i - 1][j - i] if j - i >= 0 else 0)
                    dp[i][j] = (dp[i][j - 1] + val) % M
                if j == Max: break
        return dp[n][k] % M
```

## Fastest
```
class Solution:
    def kInversePairs(self, n: int, k: int) -> int: 
        M = 10 ** 9 + 7
        dp = [0] * (k + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            ans = 0
            tmp = [0] * (k + 1)
            for j in range(k + 1):
                ans += dp[j]
                if j >= i:
                    ans -= dp[j - i]
                ans %= M
                tmp[j] = ans
            dp = tmp
        return dp[-1]
```
