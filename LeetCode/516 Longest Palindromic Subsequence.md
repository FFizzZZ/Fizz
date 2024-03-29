## Leetcode
#### Dynamic Programming
```
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[1] * n for _ in range(n)]
        
        for j in range(n):
            for i in range(j - 1, -1, -1):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2 if j - i >= 2 else 2
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])
                    
        return dp[0][-1]
```
##### Here is a trick: we can reduce space to O(2n). Really amazing!
```
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[1] * 2 for _ in range(n)]
        
        for j in range(n):
            col = j % 2
            for i in range(j - 1, -1, -1):
                if s[i] == s[j]:
                    dp[i][col] = dp[i + 1][1 - col] + 2 if j - i >= 2 else 2
                else:
                    dp[i][col] = max(dp[i][1 - col], dp[i + 1][col])
                    
        return dp[0][(n - 1) % 2]
```
##### O(n)!
```
class Solution(object):
    def longestPalindromeSubseq(self, s):
        n = len(s)
        dp = [1] * n
        for j in range(n):
            pre = None
            for i in range(j - 1, -1, -1):
                tmp = dp[i]
                if s[i] == s[j]:
                    dp[i] = pre + 2 if i + 1 <= j - 1 else 2
                else:
                    dp[i] = max(dp[i], dp[i + 1])
                pre = tmp
        return dp[0]
```

    
