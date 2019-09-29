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
        cur = pre = ans = 0
        op = "+"
        for char in s + "%":
            if char.isdigit():
                cur = cur * 10 + int(char)
            elif char != " ":
                if op == "+":
                    ans += pre
                    pre = cur
                elif op == "-":
                    ans += pre
                    pre = -cur
                elif op == "*":
                    pre *= cur
                else:
                    pre = int(pre / cur)
                op = char
                cur = 0
        return ans + pre
```
