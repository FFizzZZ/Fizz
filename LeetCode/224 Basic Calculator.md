## Leetcode
#### Stack and String Reversal
```
class Solution:
    def evaluate_expr(self, stack):
        res = stack.pop() if stack else 0
        while stack and stack[-1] != ')':
            sign = stack.pop()
            if sign == '+':
                res += stack.pop()
            else:
                res -= stack.pop()
        return res       
    def calculate(self, s: str) -> int:
        stack = []
        n, operand = 0, 0
        for i in range(len(s) - 1, -1, -1):
            ch = s[i]
            if ch.isdigit():
                operand = (10 ** n * int(ch)) + operand
                n += 1
            elif ch != " ":
                if n:
                    stack.append(operand)
                    n, operand = 0, 0
                if ch == '(':         
                    res = self.evaluate_expr(stack)
                    stack.pop()        
                    stack.append(res)
                else:
                    stack.append(ch)
        if n:
            stack.append(operand)
        return self.evaluate_expr(stack)
```
#### Stack and No String Reversal
```
class Solution:
    def calculate(self, s: str) -> int:
        ans = cur = 0
        sign = 1
        stack = []
        for char in s:
            if char.isdigit():
                cur = 10 * cur + int(char)
            elif char == "+":
                ans += sign * cur
                cur = 0
                sign = 1
            elif char == "-":
                ans += sign * cur
                cur = 0
                sign = -1
            elif char == "(":
                stack.append(ans)
                stack.append(sign)
                sign = 1
                cur = ans = 0
            elif char == ")":
                cur = ans + sign * cur
                sign = stack.pop()
                ans = stack.pop()
        return ans + sign * cur
```
