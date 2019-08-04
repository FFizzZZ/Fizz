## Leetcode
```
class Solution:
    def getSum(self, a: int, b: int) -> int:
        while b:
            c = a & b
            a ^= b
            b = c << 1
        return a
```
