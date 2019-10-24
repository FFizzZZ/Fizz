```
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        ans = []
        stack = []
        cnt = 0
        d = {"(": 1, ")": -1}
        for char in S:
            cnt += d[char]
            stack.append(char)
            if cnt == 0:
                ans.extend(stack[1:-1])
                stack = []
        return "".join(ans)
```


## Leetcode

```
class Solution:
    def removeOuterParentheses(self, S):
        ans = []
        cnt = 0
        for char in S:
            cnt += 1 if char == "(" else -1
            if char == "(" and cnt > 1:
                ans.append(char)
            if char == ")" and cnt > 0:
                ans.append(char)
        return "".join(ans)
```
