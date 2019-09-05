## Leetcode

```
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        for c in s:
            i = t.find(c)
            if i == -1:
                return False
            else:
                t = t[i+1:]
        return True
```

```
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        d = collections.defaultdict(list)
        for i, c in enumerate(t):
            d[c].append(i)
        start = 0    
        for c in s:
            index = bisect.bisect_left(d[c], start)
            if index == len(d[c]):
                return False
            else:
                start = d[c][index] + 1
        return True
```
