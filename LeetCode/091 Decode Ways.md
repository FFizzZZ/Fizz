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


