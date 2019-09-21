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
        repeat = {0: 0}
        nxt = {0: 0}
        cnt = index = 0
        for i in range(1, n1 + 1):
            for j in range(len(s1)):
                if s1[j] == s2[index]:
                    index += 1
                if index == len(s2):
                    index = 0
                    cnt += 1
            if index in nxt:
                start = nxt[index]
                prefix = repeat[start]
                pattern = (n1 - start) // (i - start) * (cnt - prefix)
                suffix = repeat[start + (n1 - start) % (i - start)] - prefix
                return (prefix + pattern + suffix) // n2
            repeat[i] = cnt
            nxt[index] = i
        return repeat[n1] // n2
```
