```
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        d = collections.Counter(t)
        l, r = 0, 0
        count = len(d)
        start, end = 0, float('inf')
        for r, v in enumerate(s):
            if v in d:
                d[v] -= 1
                if d[v] == 0: count -= 1
            while count == 0:
                temp = s[l]
                if temp in d:
                    d[temp] += 1
                    if d[temp] > 0: 
                        count += 1
                        if r - l < end - start:
                            start, end = l, r
                l += 1
        return '' if end == float('inf') else s[start:end+1]
```

## Leetcode Solution
```
from collections import Counter
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        dict_t = Counter(t)
        required = len(dict_t)
        l, r = 0, 0
        w = {}
        count = 0
        ans = len(s) + 1, None, None
        while r < len(s):
            val = s[r]
            if val in dict_t:
                w[val] = w.get(val, 0) + 1
                if w[val] == dict_t[val]:
                    count += 1
            while count == required:
                if r - l + 1 < ans[0]:
                    ans = r - l + 1, l, r
                val = s[l]
                if val in dict_t:
                    w[val] -= 1
                    if w[val] < dict_t[val]:
                        count -= 1
                l += 1
            r += 1
        return '' if ans[0] == len(s) + 1 else s[ans[1]: ans[2]+1]
```
Optimized version：remove all the elements not present in T. (actually it runs more slowly.....)
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
## shorter version
```
class Solution:
    def minWindow(self, s, t):
        need, missing = collections.Counter(t), len(t)
        i = I = J = 0
        for j, c in enumerate(s, 1):
            missing -= need[c] > 0
            need[c] -= 1
            if not missing:
                while i < j and need[s[i]] < 0:
                    need[s[i]] += 1           
                    i += 1
                if not J or j - i <= J - I:
                    I, J = i, j
        return s[I:J]
```
## Fastest!
```
from collections import defaultdict
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        d = defaultdict(int)
        for ch in t:
            d[ch] += 1
        res = 0
        i = 0
        count = len(t)
        l, r = 0, float('inf')
        for j, ch in enumerate(s, 1):
            if d[ch] > 0:
                count -= 1
            if ch in d:   
                d[ch] -= 1
            if count == 0:
                while d[s[i]] < 0:
                    d[s[i]] += 1
                    i += 1
                if j - i < r - l:
                    l = i
                    r = j
                d[s[i]] += 1
                i += 1
                count += 1
        return s[l: r] if r != float('inf') else ''
```
