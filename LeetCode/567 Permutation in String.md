## Leetcode

#### Dict
```
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m, n = len(s1), len(s2)
        if m > n: return False
        d1 = {char: 0 for char in string.ascii_lowercase}
        d2 = {char: 0 for char in string.ascii_lowercase}
        for i in range(m):
            d1[s1[i]] += 1
            d2[s2[i]] += 1
        if d1 == d2: return True
        for i in range(m, n):
            d2[s2[i]] += 1
            d2[s2[i - m]] -= 1
            if d1 == d2: return True
        return False
```
       
#### Hash
```
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:    
        m, n = len(s1), len(s2)
        target = sum(hash(x) for x in s1)
        cur = sum(hash(x) for x in s2[:m])
        if target == cur:
            return True
        for idx, char in enumerate(s2[m:n], m):
            cur += hash(char) - hash(s2[idx - m])
            if cur == target:
                return True
        return False
```
