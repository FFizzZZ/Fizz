```
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in tokens:
            if i not in '+-*/':
                stack.append(int(i))
            else:
                val1, val2 = stack.pop(), stack.pop()
                if i == '+':
                    stack.append(val1 + val2)
                elif i == '-':
                    stack.append(val2 - val1)
                elif i == '*':
                    stack.append(val1 * val2)
                else:
                    stack.append(int(val2 / val1))       
        return stack[-1]
```
