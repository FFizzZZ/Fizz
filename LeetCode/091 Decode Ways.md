## recurse with memorization
```
class Solution:
    def numDecodings(self, s: str) -> int:
        d = {}
        return self.f(0, s, d)
    def f(self, i, s, d):
        if i in d: return d[i]
        if i == len(s):
            return 1
        ans = 0
        if s[i] == '0':
            return 0
        else:
            ans += self.f(i + 1, s, d)
            if i + 1 < len(s) and int(s[i:i+2]) <= 26:
                ans += self.f(i + 2, s, d)
        d[i] = ans
        return ans
```

## dynamic programming
```
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(n):
            if s[i] != '0':
                dp[i + 1] += dp[i]
            if i > 0 and s[i -1] != '0' and int(s[i-1:i+1]) <= 26:
                dp[i + 1] += dp[i - 1]
        return dp[n]
```
Optimized version
```
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        p, q = 0, 1
        for i in range(n):
            temp = 0
            if s[i] != '0':
                temp += q
            if i > 0 and s[i - 1] != '0' and int(s[i - 1:i + 1]) <= 26:
                temp += p
            p, q = q, temp
        return q
```

## One line
```
class Solution:
    def numDecodings(self, s):
        v, w, p = 0, int(s>''), ''
        for d in s:
            v, w, p = w, (d>'0')*w + (9<int(p+d)<27)*v, d
        return w
```
