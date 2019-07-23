```
class Solution(object):
    def isHappy(self, n):
        d = {}
        while 1:
            if n in d: return False
            d[n] = 1
            val = 0
            while n:
                n, tmp = divmod(n, 10)
                val += tmp ** 2
            if val == 1: return True
            n = val
```
