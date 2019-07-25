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
        stack = []
        operand = 0
        res = 0 
        sign = 1  
        for ch in s:
            if ch.isdigit():
                operand = (operand * 10) + int(ch)
            elif ch == '+':
                res += sign * operand
                sign = 1
                operand = 0
            elif ch == '-':
                res += sign * operand
                sign = -1
                operand = 0
            elif ch == '(':
                stack.append(res)
                stack.append(sign)
                sign = 1
                res = 0
            elif ch == ')':
                res += sign * operand
                res *= stack.pop() 
                res += stack.pop() 
                operand = 0
        return res + sign * operand
```
