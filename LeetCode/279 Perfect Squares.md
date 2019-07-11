```
class Solution:
    d = {}
    def numSquares(self, n):
        if n < 2: return n
        d = self.d
        nums = []
        for i in range(1, n + 1):
            if i ** 2 > n: break
            nums.append(i ** 2)
        return self.f(n, nums, d)
    def f(self, n, nums, d):
        if n == 0: return 0
        if n in d: return d[n]
        ans = n
        for x in nums:
            if n >= x:
                temp = self.f(n - x, nums, d) + 1
                if temp < ans:
                    ans = temp
        d[n] = ans
        return ans
```
        
## Leetcode
#### BFS
```
class Solution:
    def numSquares(self, n):
        if n < 2: return n
        i = 1
        lst = []
        while i ** 2 <= n:
            lst.append(i ** 2)
            i += 1
        s = {n}
        count = 0
        while 1:
            count += 1
            temp = set()
            for x in s:
                for y in lst:
                    if x == y:
                        return count
                    elif x < y:
                        break
                    temp.add(x - y)
            s = temp
        return count
```

#### Dynamic Programming
Actually this one will get TLE!
```
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if j ** 2 > i: 
                    break
                else:
                    val = dp[i - j ** 2] + 1
                    dp[i] = val if dp[i] > val else dp[i]
        return dp[-1]
```
So here is a trick.
```
class Solution(object):
    _dp = [0]
    def numSquares(self, n):
        dp = self._dp
        while len(dp) <= n:
            dp += min(dp[-i*i] for i in range(1, int(len(dp)**0.5) + 1)) + 1,
        return dp[n]
```

#### Math
```
class Solution:
    def numSquares(self, n: int) -> int:
        while not (n%4):       #results are the same for n and 4n
            n /= 4 # 除任何平方数都不影响
        if n%8 == 7: # 这个是依据平方数只能是8n, 8n+1, 8n+4 那么8n+7都是4
            return 4
        if n %8 == 6:
            return 3
        x = math.ceil(math.sqrt(n))
        for i in range(x):
            j = math.floor(math.sqrt(n - i*i))
            if i*i + j*j == n:
                if i > 0 and j > 0:
                    return 2
                else:
                    return 1           
        return 3 
```
