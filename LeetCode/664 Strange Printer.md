## Leetcode
```
class Solution:
    def strangePrinter(self, S):
        S = re.sub(r'(.)\1*', r'\1', S)
        if not S: return 0
        n = len(S)
        d = dict()
        nxt = [n] * n
        for i in range(n - 1, -1, -1):
            val = S[i]
            if val not in d:
                d[val] = i
            else:
                nxt[i] = d[val]
                d[val] = i
        dp = [[0] * n for _ in range(n)]
        for j in range(n):
            for i in range(j, -1, -1):
                if i == j:
                    dp[i][j] = 1
                else:
                    tmp = 1 + dp[i + 1][j]
                    if S[i] == S[j]: tmp = min(tmp, dp[i][j - 1])
                    mid = nxt[i]
                    while mid < j:
                        val = dp[i][mid - 1] + dp[mid + 1][j]
                        if val < tmp: tmp = val
                        mid = nxt[mid]
                    dp[i][j] = tmp
        return dp[0][-1]
```
