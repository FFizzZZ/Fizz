```
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        d = {}
        return self.f(0, 0, 0, s1, s2, s3, d)
    def f(self, i, j, k, s1, s2, s3, d):
        if (i, j, k) in d: return d[(i, j, k)]
        if k == len(s3):
            if i == len(s1) and j == len(s2): return True
            else: return False
        ans = False
        if i < len(s1) and s1[i] == s3[k]:
            ans = self.f(i + 1, j, k + 1, s1, s2, s3, d)
        if not ans and j < len(s2) and s2[j] == s3[k]:
            ans = self.f(i, j + 1, k + 1, s1, s2, s3, d)
        d[(i, j, k)] = ans
        return ans
```

## leetcode
## dynamic programming
```
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        l1, l2, l3 = len(s1), len(s2), len(s3)
        if l1 + l2 != l3: return False
        dp = [[None] * (l2 + 1)] * (l1 + 1)
        for i in range(l1 + 1):
            for j in range(l2 + 1):
                if i == 0 and j == 0: dp[i][j] = True
                elif i == 0:
                    dp[i][j] = dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]
                elif j == 0:
                    dp[i][j] = dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]
                else:
                    dp[i][j] = dp[i - 1][j] and s1[i - 1] == s3[i + j - 1] or \
                    dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]
        return dp[-1][-1]
```
