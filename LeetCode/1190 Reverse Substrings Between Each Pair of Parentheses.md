## Leetcode

```
class Solution:
    def reverseParentheses(self, s):
        ans = [""]
        for char in s:
            if char == "(":
                ans.append("")
            elif char == ")":
                ans[len(ans) - 2] += ans.pop()[::-1]
            else:
                ans[-1] += char
        return "".join(ans)
```
