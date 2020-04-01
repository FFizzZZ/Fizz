```
class Solution:
    def addDigits(self, num: int) -> int:
        if num < 10:
            return num
        total = 0
        while num != 0:
            num, b = divmod(num, 10)
            total += b
        return self.addDigits(total)
```
