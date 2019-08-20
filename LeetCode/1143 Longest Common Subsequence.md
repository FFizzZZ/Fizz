## Leetcode
#### Dynamic Programming
```
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n1, n2 = len(text1), len(text2)
        dp = [[0] * (n2 + 1) for _ in range(n1 + 1)]
        
        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[-1][-1]
```
###### Optimized Version
```
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n1, n2 = len(text1), len(text2)
        dp = [0] * (n2 + 1)
        
        for i in range(1, n1 + 1):
            pre = 0
            for j in range(1, n2 + 1):
                tmp = dp[j]
                if text1[i - 1] == text2[j - 1]:
                    dp[j] = pre + 1
                else:
                    dp[j] = max(dp[j], dp[j - 1])
                pre = tmp
        return dp[-1]
```

#### FASTEST! But I don't understand...So sad.
```
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        if len(text1) > len(text2):
            text1, text2 = text2, text1
        m, n = len(text1), len(text2)
        za = [-1]
        
        for t1 in text1:
            loc = text2.find(t1, za[-1]+1)
            if loc != -1:
                za.append(loc)
            for j in range(len(za)-2-int(loc!=-1),-1,-1):
                loc = text2.find(t1, za[j]+1, za[j+1])
                if loc != -1:
                    za[j+1] = loc
        print(za)
        return len(za) - 1
```
