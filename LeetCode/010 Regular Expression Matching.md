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
            
# Dynamic Programming
```
class Solution(object):
    def isMatch(self, text, pattern):
        log = {}
        def dp(i, j):
            if (i,j) in log:
                return log[(i,j)]
            else:
                if j == len(pattern):
                    res = i == len(text)
                else:
                    first_match = i < len(text) and pattern[j] in ['.', text[i]]
                    if j + 1 < len(pattern) and pattern[j+1] == '*':
                        res = dp(i, j+2) or first_match and dp(i+1, j)
                    else:
                        res = first_match and dp(i+1, j+1)
                    log[(i,j)] = res
            return res
        return dp(0, 0)
```
            
# Solutions
Dynamic Programming
As the problem has an optimal substructure, it is natural to cache intermediate results. We ask the question dp(i, j): does 
text[i:] and pattern[j:] match? We can describe our answer in terms of answers to questions involving smaller strings.
# Top-down Variation
```
class Solution(object):
    def isMatch(self, text, pattern):
        memo = {}
        def dp(i, j):
            if (i, j) not in memo:
                if j == len(pattern):
                    ans = i == len(text)
                else:
                    first_match = i < len(text) and pattern[j] in {text[i], '.'}
                    if j+1 < len(pattern) and pattern[j+1] == '*':
                        ans = dp(i, j+2) or first_match and dp(i+1, j)
                    else:
                        ans = first_match and dp(i+1, j+1)

                memo[i, j] = ans
            return memo[i, j]

        return dp(0, 0)
```
#
#
# Bottom-up
```
class Solution(object):
    def isMatch(self, text, pattern):
        dp = [[False] * (len(pattern) + 1) for _ in range(len(text) + 1)]

        dp[-1][-1] = True
        for i in range(len(text), -1, -1):
            for j in range(len(pattern) - 1, -1, -1):
                first_match = i < len(text) and pattern[j] in {text[i], '.'}
                if j+1 < len(pattern) and pattern[j+1] == '*':
                    dp[i][j] = dp[i][j+2] or first_match and dp[i+1][j]
                else:
                    dp[i][j] = first_match and dp[i+1][j+1]

        return dp[0][0]
```
