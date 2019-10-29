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

```
class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        for char in s:
            if char == ")":
                tmp = ""
                while stack and stack[-1] != "(":
                    tmp += stack.pop()[::-1]
                stack.pop()
                stack.append(tmp)
            else:
                stack.append(char)
        return "".join(stack)
```
