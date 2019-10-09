## Leetcode
dp[1] = 10  
dp[2] = dp[1] + 9 * 9  
dp[3] = dp[2] + 9 * 9 * 8  
...

```
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0: return 1
        ans = 10
        unique = 9
        available = 9
        for i in range(n - 1):
            unique *= available
            ans += unique
            available -= 1
        return ans
```
