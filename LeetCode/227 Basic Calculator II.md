## Leetcode
#### stack
```
class Solution:
    def calculate(self, s: str) -> int:
        res = []
        symb = '+'
        curNum = 0
        for c in s+'/':
            if c.isdigit():
                curNum *= 10
                curNum += int(c)
            elif c !=' ':
                if symb == '+': res.append(curNum)
                elif symb == '-': res.append(-curNum)
                elif symb == '*': res.append(res.pop()*curNum)
                elif symb == '/': res.append(int(res.pop()/curNum))
                symb = c
                curNum = 0
        return sum(res)
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
