## Leetcode
#### stack
```
class Solution:
    def calculate(self, s: str) -> int:
        cur = 0
        op = "+"
        stack = []
        for char in s + "%":
            if char.isdigit():
                cur = cur * 10 + int(char)
            elif char != " ":
                if op == "+":
                    stack.append(cur)
                elif op == "-":
                    stack.append(-cur)
                elif op == "*":
                    stack.append(cur * stack.pop())
                else:
                    stack.append(int(stack.pop() / cur))
                op = char
                cur = 0
        return sum(stack)
```
#### without stack
```
class Solution:
    def calculate(self, s: str) -> int:
        op = '+'
        tmp = 0
        num = 0
        ans = 0
        for i in s + '+':
            if i.isdigit():
                num *= 10
                num += int(i)
            elif i != ' ':
                if op == '+':
                    ans += tmp
                    tmp = num
                elif op == '-':
                    ans += tmp
                    tmp = -num
                elif op == '*':
                    tmp *= num
                elif op == '/':
                    tmp = int(tmp / num)
                op = i
                num = 0
        ans += tmp
        return ans
```
