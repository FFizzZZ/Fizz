```
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 9 if s[0] == "*" else (0 if s[0] == "0" else 1)
        M = 10 ** 9 + 7
        for i in range(1, n):
            if s[i] == "*":
                dp[i + 1] = 9 * dp[i]
                if s[i - 1] == "1":
                    dp[i + 1] = (dp[i + 1] + 9 * dp[i - 1]) % M
                elif s[i - 1] == "2":
                    dp[i + 1] = (dp[i + 1] + 6 * dp[i - 1]) % M
                elif s[i - 1] == "*":
                    dp[i + 1] = (dp[i + 1] + 15 * dp[i - 1]) % M
            else:
                dp[i + 1] = dp[i] if s[i] != "0" else 0
                if s[i - 1] == "1":
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M
                elif s[i - 1] == "2" and s[i] <= "6":
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M
                elif s[i - 1] == "*":
                    dp[i + 1] = (dp[i + 1] + (2 if s[i] <= "6" else 1) * dp[i - 1]) % M
        return dp[-1]
```

```
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        first = 1
        second = 9 if s[0] == "*" else (0 if s[0] == "0" else 1)
        M = 10 ** 9 + 7
        for i in range(1, n):
            if s[i] == "*":
                tmp = 9 * second
                if s[i - 1] == "1":
                    tmp = (tmp + 9 * first) % M
                elif s[i - 1] == "2":
                    tmp = (tmp + 6 * first) % M
                elif s[i - 1] == "*":
                    tmp = (tmp + 15 * first) % M
            else:
                tmp = second if s[i] != "0" else 0
                if s[i - 1] == "1":
                    tmp = (tmp + first) % M
                elif s[i - 1] == "2" and s[i] <= "6":
                    tmp = (tmp + first) % M
                elif s[i - 1] == "*":
                    tmp = (tmp + (2 if s[i] <= "6" else 1) * first) % M
            first, second = second, tmp
        return second
```
