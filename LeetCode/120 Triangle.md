```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        d = {}
        return self.f(0, 0, triangle, d)
    def f(self, i, j, triangle, d):
        if i == len(triangle):
            return 0
        if (i, j) in d: return d[(i, j)]
        l = self.f(i + 1, j, triangle, d)
        r = self.f(i + 1, j + 1, triangle, d)
        ans = min(l, r) + triangle[i][j]
        d[(i, j)] = ans
        return ans
```

## Leetcode
Bottom-up is easier than top-down
```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        l = len(triangle)
        dp = triangle[-1][:]
        for i in range(l - 2, -1, -1):
            for j in range(i + 1):
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j]
        return dp[0]
```
top-down
```
class Solution:
    def minimumTotal(self, triangle):
        if not triangle:
            return 
        res = [[0 for i in range(len(row))] for row in triangle]
        res[0][0] = triangle[0][0]
        for i in range(1, len(triangle)):
            for j in range(len(triangle[i])):
                if j == 0:
                    res[i][j] = res[i-1][j] + triangle[i][j]
                elif j == len(triangle[i])-1:
                    res[i][j] = res[i-1][j-1] + triangle[i][j]
                else:
                    res[i][j] = min(res[i-1][j-1], res[i-1][j]) + triangle[i][j]
        return min(res[-1])
```
