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
