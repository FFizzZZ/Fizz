```
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
```

```
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        d = collections.defaultdict(int)
        for i in s:
            d[i] += 1
        for i in t:
            d[i] -= 1
            if d[i] < 0: 
                return False
        return True
```

```
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        return collections.Counter(s) == collections.Counter(t)
```
#### Fastest
```
class Solution:
    def isAnagram(self,s,t):
        if len(s) != len(t):
            return False
        for char in set(s):
            if s.count(char) != t.count(char):
                return False
        return True
```
