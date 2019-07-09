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
