```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:                
        if len(s) < len(p) - p.count('*'): return False
        dp = dict()
        m, n = len(s), len(p)
        def dfs(i, j):
            if j == n: return i == m
            if i == m: return p[j] == '*' and dfs(i, j + 1)
            if (i, j) in dp: return dp[i, j]
            first_match = i < m and p[j] in ['?', s[i]]
            pattern = p[j]
            if pattern == '*':
                ans = dfs(i + 1, j) or dfs(i, j + 1)
            else:
                ans = first_match and dfs(i + 1, j + 1)
            dp[i, j] = ans
            return ans
        return dfs(0, 0)
```
## Leetcode                
#### FASTEST
```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        i, j = 0, 0
        m, n = len(s), len(p)
        start = -1
        while i < m:
            if j < n and p[j] in ['?', s[i]]:
                i += 1
                j += 1
            elif j < n and p[j] == '*':
                start = j
                start_s = i
                j += 1
            elif start != -1:
                start_s += 1
                i = start_s
                j = start + 1
            else:
                return False
        while j < n and p[j] == '*':
            j += 1
        return j == n
```

#### dp
```
class Solution:
# @return a boolean
def isMatch(self, s, p):
    length = len(s)
    if len(p) - p.count('*') > length:
        return False
    dp = [True] + [False]*length
    for i in p:
        if i != '*':
            for n in reversed(range(length)):
                dp[n+1] = dp[n] and (i == s[n] or i == '?')
        else:
            for n in range(1, length+1):
                dp[n] = dp[n-1] or dp[n]
        dp[0] = dp[0] and i == '*'
    return dp[-1]
```



