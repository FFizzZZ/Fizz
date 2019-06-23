## Recurse
```
class Solution:
    def isScramble(self, s1, s2):
        if s1 == s2:
            return True
        if sorted(s1) != sorted(s2): # prunning
            return False
        for i in range(1, len(s1)):
            if (self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:])) or \
            (self.isScramble(s1[:i], s2[-i:]) and self.isScramble(s1[i:], s2[:-i])):
                return True
        return False
```
## Recurse with memorization
```
class Solution:
    def __init__(self):
        self.dic = {}
    def isScramble(self, s1, s2):
        if (s1, s2) in self.dic:
            return self.dic[(s1, s2)]
        if len(s1) != len(s2) or sorted(s1) != sorted(s2): # prunning
            self.dic[(s1, s2)] = False
            return False
        if s1 == s2:
            self.dic[(s1, s2)] = True
            return True
        for i in range(1, len(s1)):
            if (self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:])) or \
            (self.isScramble(s1[:i], s2[-i:]) and self.isScramble(s1[i:], s2[:-i])):
                return True
        self.dic[(s1, s2)] = False
        return False
```

## dynamic programming (it is slow!)
```
class Solution:
    def isScramble(self, s1, s2):
        if len(s1) != len(s2): return False
        if s1 == s2: return True
        if sorted(s1) != sorted(s2): return False
        l = len(s1)
        dp = [[[0] * l for _ in range(l)] for _ in range(l + 1)]
        for n in range(1, l + 1):
            for i in range(l - n + 1):
                for j in range(l - n + 1):
                    if n == 1: dp[n][i][j] = s1[i] == s2[j]
                    else:
                        for q in range(1, n):
                            dp[n][i][j] = dp[q][i][j] and dp[n - q][i + q][j + q] or \
                            dp[q][i][j + n - q] and dp[n - q][i + q][j]
                            if dp[n][i][j]: break
        return dp[l][0][0]
```
