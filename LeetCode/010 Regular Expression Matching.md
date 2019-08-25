# Recursion
```
class Solution:
    def isMatch(self, s: 'str', p: 'str') -> 'bool':
        if not p: return not s
        first_match = bool(s) and p[0] in {s[0], '.'}
        
        if len(p) >= 2 and p[1] == '*':
            return (self.isMatch(s, p[2:]) or first_match and self.isMatch(s[1:], p))
        else:
            return first_match and self.isMatch(s[1:], p[1:])
```
# Solutions
Dynamic Programming
As the problem has an optimal substructure, it is natural to cache intermediate results. We ask the question dp(i, j): does 
text[i:] and pattern[j:] match? We can describe our answer in terms of answers to questions involving smaller strings.
# Top-down Variation
```
class Solution(object):
    def isMatch(self, s, p):
        n1, n2 = len(s), len(p)
        d = dict()
        def dp(i, j):
            if (i, j) in d: return d[(i, j)]
            if j == n2: return i == n1
            first = i < n1 and p[j] in ['.', s[i]]
            if j + 1 < n2 and p[j + 1] == '*':
                ans = dp(i, j + 2) or first and dp(i + 1, j)
            else:
                ans = first and dp(i + 1, j + 1)
            d[(i, j)] = ans
            return ans
        return dp(0, 0)
```

# Bottom-up
```
class Solution(object):
    def isMatch(self, s, p):
        n1, n2 = len(s), len(p)
        dp = [[False] * (n2 + 1) for _ in range(n1 + 1)]
        dp[-1][-1] = True
        for i in range(n1, -1, -1):
            for j in range(n2 - 1, -1, -1):
                first = i < n1 and p[j] in ['.', s[i]]
                if j + 1 < n2 and p[j + 1] == '*':
                    dp[i][j] = dp[i][j + 2] or first and dp[i + 1][j]
                else:
                    dp[i][j] = first and dp[i + 1][j + 1]
        return dp[0][0]
```
