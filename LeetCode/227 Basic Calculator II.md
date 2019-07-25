## Leetcode
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
