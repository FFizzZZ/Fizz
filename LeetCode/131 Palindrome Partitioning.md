## recurse
```
class Solution(object):
    def partition(self, s):
        ans = []
        for i in range(1, len(s) + 1):
            if s[:i] == s[i-1::-1]:
                for j in self.partition(s[i:]):
                    ans.append([s[:i]] + j)
        return ans if ans else [[]]
```

## recurse with memo
```
class Solution(object):
    def partition(self, s):
        d = {}
        return self.f(s, 0, d)
    def f(self, s, start, d):
        if start in d:
            return d[start]
        ans = []
        for i in range(start + 1, len(s) + 1):
            if s[start:i] == s[i-1:start:-1] + s[start]:
                for j in self.f(s, i, d):
                    ans.append([s[start:i]] + j)
        ans = ans if ans else [[]]
        d[start] = ans
        return ans
```
