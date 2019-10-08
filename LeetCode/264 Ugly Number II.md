## Leetcode
#### Dynamic Programming
```
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        if n <= 0: return False
        p1, p2, p3 = 0, 0, 0
        dp = [1] * n
        for i in range(1, n):
            dp[i] = min(dp[p1] * 2, dp[p2] * 3, dp[p3] * 5)
            if dp[i] == dp[p1] * 2: p1 += 1
            if dp[i] == dp[p2] * 3: p2 += 1
            if dp[i] == dp[p3] * 5: p3 += 1
        return dp[-1]
```
#### Trick
```
class Solution:
    dp = [1] * 1690
    p2 = p3 = p5 = 0
    for i in range(1, 1690):
        val = min(dp[p2] * 2, dp[p3] * 3, dp[p5] * 5)
        dp[i] = val
        if val == dp[p2] * 2: p2 += 1
        if val == dp[p3] * 3: p3 += 1
        if val == dp[p5] * 5: p5 += 1
    def nthUglyNumber(self, n):
        return self.dp[n - 1]
```


```
from itertools import product
class Solution:
    ugly = sorted([ 2 ** i * 3 ** j * 5 ** k for i, j, k in product(range(31), range(21), range(16))])
    def nthUglyNumber(self, n: int) -> int:
        return self.ugly[n-1]
```
