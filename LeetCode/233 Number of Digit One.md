## 剑指offer
```
class Solution:
    def countDigitOne(self, n: int) -> int:
        if n <= 0: return 0
        if n < 10: return 1
        first, remain = int(str(n)[0]), int(str(n)[1:])
        length = len(str(n)) - 1
        cnt = 0
        if first == 1:
            cnt += remain + 1
        else:
            cnt += 10 ** length
        cnt += first * length * 10 ** (length - 1)
        return cnt + self.countDigitOne(remain)
```
