## dynamic programming
```
class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[0], dp[1] = 1, 1
        for i in range(2, n+1):
            dp[i] += dp[i-1] + dp[i-2]
        return dp[-1]
```

## recurse with memo
```
class Solution:
    def climbStairs(self, n: int) -> int:
        d = {}
        return self.f(n, d)
    def f(self, n, d):
        if n in d: return d[n]
        if n == 1:
            return 1
        if n == 2:
            return 2
        d[n] = self.f(n-1, d) + self.f(n-2, d)
        return d[n]
```

## Fibonacci Number
```
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1: return 1
        first, second = 1, 2
        for i in range(3, n+1):
            first, second = second, first + second
        return second
```

## Fibonacci Formula
```
class Solution:
    def climbStairs(self, n: int) -> int:
        return int((((1 + 5 ** 0.5) / 2) ** (n + 1) - ((1 - 5 ** 0.5) / 2) ** (n + 1)) / 5 ** 0.5)
```


