## Leetcode
```
class Solution:
    def firstUniqChar(self, s: str) -> int:
        count = collections.Counter(s)
        for idx, ch in enumerate(s):
            if count[ch] == 1:
                return idx     
        return -1
```

```
class Solution:
    def firstUniqChar(self, s: str) -> int:    
        letters='abcdefghijklmnopqrstuvwxyz'
        index=[s.index(l) for l in letters if s.count(l) == 1]
        return min(index) if len(index) > 0 else -1
```

```
class Solution:
    def firstUniqChar(self, s: str) -> int:
        uniq = []
        first = len(s)
        for letter in set(s):
            pos = s.find(letter)
            rep = s.rfind(letter)
            if pos == rep and pos < first:
                first = pos
        return first if first < len(s) else -1
```
