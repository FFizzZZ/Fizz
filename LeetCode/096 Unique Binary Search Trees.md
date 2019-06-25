## Dynamic programming
```
class Solution:
    def numTrees(self, n: int) -> int:
        if n == 0: return 0
        dp = [1] * (n + 1)
        for i in range(2, n + 1):
            ans = 0
            for j in range(1, i + 1):
                ans += dp[j - 1] * dp[i - j]
            dp[i] = ans
        return dp[n]
```


## Catalan Number
(2n)!/((n+1)!*n!)  
https://zh.wikipedia.org/wiki/%E5%8D%A1%E5%A1%94%E5%85%B0%E6%95%B0
```
class Solution:
    def numTrees(self, n):
        return math.factorial(2*n)/(math.factorial(n)*math.factorial(n+1))
```


