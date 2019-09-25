```
class Solution:
    def integerReplacement(self, n: int) -> int:
        return self.dfs(n, dict())
    def dfs(self, n, d):
        if n == 1: return 0
        if n in d: return d[n]
        if n & 1:
            ans =  1 + min(self.dfs(n + 1, d), self.dfs(n - 1, d)) 
        else:
            ans = 1 + self.dfs(n // 2, d)
        d[n] = ans
        return ans
```

## Leetcode
```
class Solution:
    def integerReplacement(self, n: int) -> int:
        cnt = 0
        while n != 1:
            if n % 2 == 0:
                n //= 2
            elif n % 4 == 1 or n == 3:
                n -= 1
            else:
                n += 1
            cnt += 1
        return 
```
