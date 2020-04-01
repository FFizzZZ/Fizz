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
## Leetcode
#### Math
```
class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0:
            return 0
        return 1 + (num - 1) % 9
```
证明 https://www.zhihu.com/question/30972581
