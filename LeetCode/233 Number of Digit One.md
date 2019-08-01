## Recurse
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

## Iterative
```
class Solution:
    def countDigitOne(self, n):
        ones, m = 0, 1
        while n >= m:
            multiply, digit = divmod(n // m, 10)
            ones += multiply * m
            if digit >= 2:
                ones += m
            elif digit == 1:
                ones += n % m + 1
            m *= 10
        return ones  
```
#### with some tricks
```
class Solution:
    def countDigitOne(self, n):    
        ones, m = 0, 1
        while m <= n:
            ones += (n // m + 8) // 10 * m + (n // m % 10 == 1) * (n % m + 1)
            m *= 10
        return ones
```
