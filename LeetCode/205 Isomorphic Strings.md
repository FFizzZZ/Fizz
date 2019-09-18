## Leetcode
```
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        return len(set(zip(s, t))) == len(set(s)) == len(set(t))
```



```
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        d1 = collections.defaultdict(int)
        d2 = collections.defaultdict(int)
        for i in range(len(s)):
            if d1[s[i]] != d2[t[i]]:
                return False
            d1[s[i]] = i + 1
            d2[t[i]] = i + 1
        return True
```
