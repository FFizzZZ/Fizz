## Leetcode
```
class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        n1, n2 = len(str1), len(str2)
        dp = [''] * (n2 + 1) 
        for i in range(n1):
            pre = ''
            for j in range(n2):
                tmp = dp[j + 1]
                if str1[i] == str2[j]:
                    dp[j + 1] = pre + str1[i]
                elif len(tmp) > len(dp[j]):
                    dp[j + 1] = tmp
                else:
                    dp[j + 1] = dp[j]
                pre = tmp
        
        i, j = 0, 0
        ans = ''
        lcs = dp[-1]
        
        for char in lcs:
            while str1[i] != char:
                ans += str1[i]
                i += 1
            while str2[j] != char:
                ans += str2[j]
                j += 1
            ans += char
            i += 1
            j += 1
        
        return ans + str1[i:] + str2[j:]
```
