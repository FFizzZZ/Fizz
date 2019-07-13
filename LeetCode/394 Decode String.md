```
class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        ans = ''
        digit = ''
        for i in s:
            if i.isdigit():
                digit += i
            elif i == '[':
                stack.append([int(digit), ''])
                digit = ''
            elif i == ']':
                n, temp = stack.pop()
                if not stack:
                    ans += temp * n
                else:
                    stack[-1][1] += temp * n
            else:
                if stack:
                    stack[-1][1] += i
                else:
                    ans += i
        return ans
```

## Leetcode
```
class Solution(object):
    def decodeString(self, s):
        stack = []
        stack.append(["", 1])
        num = ""
        for ch in s:
            if ch.isdigit():
                num += ch
            elif ch == '[':
                stack.append(["", int(num)])
                num = ""
            elif ch == ']':
                st, k = stack.pop()
                stack[-1][0] += st*k
            else:
                stack[-1][0] += ch
        return stack[0][0]
```
