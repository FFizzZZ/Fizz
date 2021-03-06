```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        count = 0
        d = []
        res = 1
        while count < abs(n):
            if not d:
                res *= x
                count += 1
                d.append([1, res])
            else:
                i = len(d) - 1
                while d[i][0] > abs(n) - count:
                    i -= 1
                count += d[i][0]
                res *= d[i][1]
                if count > d[-1][0]:
                    d.append([count, res])
        if n < 0: res = 1 / res
        return res
```
        
```
class Solution:
    def myPow(self, x, n):
        if n == 0: return 1
        elif abs(n) == 1:
            if n == 1: return x
            else: return 1 / x
        else:   
            l = bin(abs(n))[2:]
            component = [x]
            for i in range(len(l)):
                component.append(component[-1] * component[-1])
            res = 1
            for i in range(len(l)):
                if l[i] == '1':
                    res *= component[len(l)-1-i]
            if n < 0: res = 1 / res
            return res
```
                
## Leetcode
#### Recursive
```
class Solution:
    def myPow(self, x, n):
        if not n:
            return 1
        if n < 0:
            return 1 / self.myPow(x, -n)
        if n % 2:
            return x * self.myPow(x, n-1)
        return self.myPow(x*x, n/2)
```

#### Iterative
```
class Solution:
    def myPow(self, x, n):
        if n < 0:
            x = 1 / x
            n = -n
        pow = 1
        while n:
            if n & 1:
                pow *= x
            x *= x
            n >>= 1
        return pow
```
















