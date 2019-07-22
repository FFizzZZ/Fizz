```
class Solution:
    def titleToNumber(self, s: str) -> int:
        l = len(s)
        ans = 0
        for i in range(l):
            val = ord(s[l - i - 1]) - ord('A')
            ans += val * 26 ** i + 26 ** i
        return ans
```

## Leetcode
```
class Solution:
    def titleToNumber(self, s: str) -> int:
        ans = 0
        for i in range(len(s)):
            ans = ans * 26 + ord(s[i]) - ord('A') + 1
        return ans
```


```
import functools 
class Solution:
    def titleToNumber(self, s: str) -> int:
        return functools.reduce(lambda x, y : x * 26 + y, [ord(c) - 64 for c in list(s)])
```
