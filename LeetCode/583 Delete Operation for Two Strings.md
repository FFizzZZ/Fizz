```
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1, n2 = len(word1), len(word2)
        if n1 > n2:
            word1, word2 = word2, word1
            n1, n2 = n2, n1
        dp = [0] * (n1 + 1)
        
        for j in range(1, n2 + 1):
            pre = 0
            for i in range(1, n1 + 1):
                tmp = dp[i]
                if word1[i - 1] == word2[j - 1]:
                    dp[i] = pre + 1
                else:
                    dp[i] = max(dp[i - 1], tmp)
                pre = tmp
        
        cnt = dp[-1]
        return n1 + n2 - 2 * cnt
```

## Leetcode
#### Directly
```
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1, n2 = len(word1), len(word2)
        dp = [[0] * (n2 + 1) for _ in range(n1 + 1)]
        
        for i in range(n1 + 1):
            for j in range(n2 + 1):
                if i == 0 or j == 0:
                    dp[i][j] = i + j
                elif word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1
        
        return dp[-1][-1]
```
