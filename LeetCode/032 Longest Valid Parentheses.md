## Stack
```
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        ans = 0
        stack = [-1]
        for idx, char in enumerate(s):
            if char == '(':
                stack.append(idx)
            else:
                stack.pop()
                if not stack:
                    stack.append(idx)
                else:
                    ans = max(ans, idx - stack[-1])
        return ans
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
                
## Two Scan without Extra Space
```
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        left = right = ans = 0
        for char in s:
            if char == '(': left += 1
            else: right += 1
            if left == right: ans = max(ans, 2 * left)
            elif right > left: left = right = 0
        left = right = 0
        for char in reversed(s):
            if char == '(': left += 1
            else: right += 1
            if left == right: ans = max(ans, 2 * left)
            elif left > right: left = right = 0
        return ans
```
