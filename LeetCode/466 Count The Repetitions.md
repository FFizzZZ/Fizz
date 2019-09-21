## Leetcode
#### Brute Force TLE
```
class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        index = cnt = 0
        for i in range(n1):
            for j in range(len(s1)):
                if s1[j] == s2[index]:
                    index += 1
                if index == len(s2):
                    cnt += 1
                    index = 0
        return cnt // n2
```
        
#### Optimized Version
```
class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        repeat = {0:0}
        nxt = {0:0}
        cnt = 0
        j = 0
        for k in range(1, n1 + 1):
            for i in range(len(s1)):
                if s1[i] == s2[j]:
                    j += 1
                if j == len(s2):
                    j = 0
                    cnt += 1
            if j in nxt:
                start = nxt[j]
                prefix = repeat[start]
                pattern = (n1 - start) // (k - start) * (cnt - prefix)
                suffix = repeat[start + (n1 - start) % (k - start)] - prefix
                return (prefix + pattern + suffix) // n2
            repeat[k] = cnt
            nxt[j] = k
        return repeat[n1] // n2
```
