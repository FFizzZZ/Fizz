* https://www.cnblogs.com/aguncn/p/10656983.html


```
class Solution:
    def in2post(self, expr):
        ans = []
        stack = []
        order = {'+': 0, '-': 0, '*': 1, '/': 1, '×': 1, '(': -1}
        for char in expr:
            if char.isdigit():
                ans.append(char)
            elif char == '(':
                stack.append(char)
            elif char == ')':
                while stack[-1] != '(':
                    ans.append(stack.pop())
                stack.pop()
            else:
                while stack and order[stack[-1]] >= order[char]:
                    ans.append(stack.pop())
                stack.append(char)
        while stack:
            ans.append(stack.pop())
        return " ".join(ans)
```

```
class Solution:
    def in2pre(self, expr):
        ans = []
        stack = []
        order = {'+': 0, '-': 0, '*': 1, '/': 1, '×': 1, ')': -1}
        for char in reversed(expr):
            if char.isdigit():
                ans.append(char)
            elif char == ')':
                stack.append(char)
            elif char == '(':
                while stack[-1] != ')':
                    ans.append(stack.pop())
                stack.pop()
            else:
                while stack and order[stack[-1]] > order[char]:  # Pay Attention to Here!
                    ans.append(stack.pop())
                stack.append(char)
        while stack:
            ans.append(stack.pop())
        return " ".join(reversed(ans))
```
