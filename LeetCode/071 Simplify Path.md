## Leetcode
```
class Solution:
    def simplifyPath(self, path):
        stack = []
        for d in path.split("/"):
            if d == "..":
                if stack:
                    stack.pop()
            elif d and d != '.':
                stack.append(d)
        return "/" + "/".join(stack)
```
