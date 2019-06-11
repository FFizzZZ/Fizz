```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        temp = 0
        ans = ''
        while a or b or temp:
            x = int(a[-1]) if a else 0
            y = int(b[-1]) if b else 0
            a = a[:-1]
            b = b[:-1]
            s = x + y + temp
            temp = 0
            if s == 0 or s == 1:
                ans = str(s) + ans
            elif s == 2:
                ans = '0' + ans
                temp = 1
            else:
                ans = '1' + ans
                temp = 1
        return ans
```
