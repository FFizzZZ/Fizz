## Leetcode
```
class Solution:
    def countPalindromicSubsequences(self, S: str) -> int:
        n = len(S)
        dp = [[0] * n for _ in range(n)]
        for j in range(n):
            for i in range(j, -1, -1):
                if i == j:
                    dp[i][i] = 1
                    continue
                if S[i] == S[j]:
                    l = i + 1
                    r = j - 1
                    val = S[j]
                    while l <= r and S[l] != val:
                        l += 1
                    while l <= r and S[r] != val:
                        r -= 1
                    if l > r:
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2
                    elif l == r:
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1
                    else:
                        dp[i][j] = dp[i + 1][j - 1] * 2 - dp[l + 1][r - 1]
                else:
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]
        return dp[0][-1] % (10 ** 9 + 7)
```
