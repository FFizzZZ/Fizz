## Leetcode Solution
```
from collections import Counter
class Solution:
    def minWindow(self, s, t):
        if not t or not s:
            return ""
        dict_t = Counter(t)
        required = len(dict_t)
        l, r = 0, 0
        formed = 0
        window_counts = {}
        ans = float("inf"), None, None
        while r < len(s):
            character = s[r]
            window_counts[character] = window_counts.get(character, 0) + 1
            if character in dict_t and window_counts[character] == dict_t[character]:
                formed += 1
            while l <= r and formed == required:
                character = s[l]
                if r - l + 1 < ans[0]:
                    ans = (r - l + 1, l, r)
                window_counts[character] -= 1
                if character in dict_t and window_counts[character] < dict_t[character]:
                    formed -= 1
                l += 1    
            r += 1    
        return "" if ans[0] == float("inf") else s[ans[1] : ans[2] + 1]
```
Optimized version (actually it runs more slowly.....)
```
from collections import Counter
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        dict_t = Counter(t)
        required = len(dict_t)
        filtered_s = []
        for i, char in enumerate(s):
            if char in dict_t:
                filtered_s.append((i, char))
        l, r = 0, 0
        formed = 0
        window_counts = {}
        ans = float("inf"), None, None
        while r < len(filtered_s):
            character = filtered_s[r][1]
            window_counts[character] = window_counts.get(character, 0) + 1
            if window_counts[character] == dict_t[character]:
                formed += 1
            while l <= r and formed == required:
                character = filtered_s[l][1]
                end = filtered_s[r][0]
                start = filtered_s[l][0]
                if end - start + 1 < ans[0]:
                    ans = (end - start + 1, start, end)
                window_counts[character] -= 1
                if window_counts[character] < dict_t[character]:
                    formed -= 1
                l += 1    
            r += 1    
        return "" if ans[0] == float("inf") else s[ans[1] : ans[2] + 1]
```
