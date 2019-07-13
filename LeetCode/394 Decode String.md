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
