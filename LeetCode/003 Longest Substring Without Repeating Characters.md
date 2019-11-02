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
        d = dict()
        for r, val in enumerate(s):
            if val in d:
                if d[val] + 1 > l:
                    l = d[val] + 1
            tmp = r - l + 1
            if tmp > ans: ans = tmp
            d[val] = r
        return ans
```

```
class Solution:
    def lengthOfLongestSubstring(self, s: 'str') -> 'int':
        cur = ""
        ans = 0
        for char in s:
            if char not in cur:
                cur += char
            else:
                if len(cur) > ans:
                    ans = len(cur)
                cur = cur.split(char)[-1] + char
        return max(len(cur), ans)
```



