```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1: return len(s)
        l, r = 0, 0
        ans = 1
        d = {}
        while r < len(s):
            if s[r] not in d:
                d[s[r]] = 1
                ans = max(ans, r - l + 1)
            else:
                while s[l] != s[r]:
                    del d[s[l]]
                    l += 1
                l += 1
            r += 1
        return ans
```

## Leetcode
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = ans = 0
        d = {}
        for r, v in enumerate(s):
            if v in d:
                temp = d[v] + 1
                if temp > l:
                    l = temp
            temp = r - l + 1
            if temp > ans:
                ans = temp
            d[v] = r
        return ans
```

```
class Solution:
    def lengthOfLongestSubstring(self, s: 'str') -> 'int':
        sub = ''
        res = ''
        for i in s:
            if not i in sub:
                sub += i
            else:
                if len(res) < len(sub):
                    res = sub
                sub = sub.split(i)[-1] + i
        return max(len(sub), len(res))
```



