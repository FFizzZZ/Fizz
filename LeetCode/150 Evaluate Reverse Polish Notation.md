```
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in tokens:
            if i == '+':
                val1 = stack.pop()
                val2 = stack.pop()
                val = val1 + val2
                stack.append(val)
            elif i == '-':
                val1 = stack.pop()
                val2 = stack.pop()
                val = val2 - val1
                stack.append(val)
            elif i == '*':
                val1 = stack.pop()
                val2 = stack.pop()
                val = val1 * val2
                stack.append(val)
            elif i == '/':
                val1 = stack.pop()
                val2 = stack.pop()
                val = int(val2 / val1)
                stack.append(val)
            else:
                stack.append(int(i))
        return stack[-1]
```
