# Using Stack
```
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if not s: return 0
        stack = [-1]
        res = 0
        for i in range(len(s)):
            if s[i] is '(':
                stack.append(i)
            else:
                stack.pop()
                if stack:
                    res = max(i - stack[-1], res)
                else:
                    stack.append(i)
        return res
```


# Using stack
```
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp, stack = [0]*(len(s) + 1), []
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                if stack:
                    p = stack.pop()
                    dp[i + 1] = dp[p] + i - p + 1
        return max(dp)
```


## Dynamic Programming
```
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        ans = 0
        dp = [0] * len(s)
        for i in range(1, len(s)):
            if s[i] == ')':
                if s[i - 1] == '(':
                    dp[i] = (dp[i - 2] if i >= 2 else 0) + 2
                elif i - dp[i - 1] > 0 and s[i - dp[i - 1] - 1] == '(':
                    dp[i] = dp[i - 1] + (dp[i - dp[i - 1] - 2] if i - dp[i - 1] >= 2 else 0) + 2
                ans = max(ans, dp[i])
        return ans
```
```
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if not s or len(s) == 1: return 0
        dp = [0] * len(s)
        if s[0] == '(' and s[1] == ')': dp[1] = 2
        for i in range(2, len(s)):
            if s[i] == ')' and s[i-1] == '(':
                dp[i] = dp[i-2] + 2
            if s[i] == ')' and s[i-1] == ')' and s[i-1-dp[i-1]] == '(' and i-1-dp[i-1] >=0:
                dp[i] = dp[i-1] + dp[i-1-dp[i-1]-1] + 2
        return max(dp)
```
                
