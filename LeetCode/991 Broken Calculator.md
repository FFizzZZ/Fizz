## Leetcode
```
class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        cnt = 0
        
        while Y > X:
            cnt += 1
            if Y & 1:
                Y += 1
            else:
                Y //= 2
        
        return cnt + X - Y
```
