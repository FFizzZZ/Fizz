## Leetcode
```
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        d = dict()
        for char1, char2 in zip(s, t):
            if char1 not in d:
                if char2 in d.values(): return False
                d[char1] = char2
            else:
                if d[char1] != char2:
                    return False
        return True
```

```
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        return len(set(zip(s, t))) == len(set(s)) == len(set(t))
```


