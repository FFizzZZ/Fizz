```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        l = 0
        d = set()
        for r, char in enumerate(s):
            if char not in d:
                d.add(char)
                val = r - l + 1
                if val > ans: ans = val
            else:
                while s[l] != char:
                    d.remove(s[l])
                    l += 1
                l += 1
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



