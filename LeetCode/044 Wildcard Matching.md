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

```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [True] * (n + 1)
        for j in range(1, n + 1):
            dp[j] = dp[j - 1] and p[j - 1] == '*'
        for i in range(1, m + 1):
            for j in range(n + 1):
                tmp = dp[j]
                if j == 0:
                    dp[j] = False
                elif p[j - 1] == '*':
                    dp[j] = dp[j] or dp[j - 1]
                elif p[j - 1] in ["?", s[i - 1]]:
                    dp[j] = pre
                else:
                    dp[j] = False
                pre = tmp
        return dp[-1]
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

#### Dynamic Programming
```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        if len(p) - p.count('*') > m: return False
        dp = [True] + [False] * m
        for char in p:
            if char == '*':
                for i in range(1, m + 1):
                    dp[i] = dp[i - 1] or dp[i]
            else:
                for i in range(m, 0, -1):
                    dp[i] = dp[i - 1] and (char == s[i - 1] or char == '?')
            dp[0] = dp[0] and char == '*'
        return dp[-1]
```



