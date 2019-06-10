```
class Solution(object):
    def uniquePathsWithObstacles(self, A):
        m, n = len(A), len(A[0])
        d = {}
        if A[0][0] == 1 or A[-1][-1] == 1: return 0
        def move(i, j):
            if (i, j) in d: return d[(i, j)]
            if i == m - 1 and j == n - 1: return 1
            if A[i][j] == 1: return 0
            temp = 0
            if i + 1 < m:
                temp += move(i+1, j)
            if j + 1 < n:
                temp += move(i, j+1)
            d[(i, j)] = temp
            return temp
        return move(0, 0)
```

```
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        temp = obstacleGrid[-1][::-1]
        if 1 in temp:
            index = temp.index(1)
            obstacleGrid[-1][:n-index-1] = [1] * (n - index - 1)
        temp = [obstacleGrid[i][-1] for i in range(m-1,-1,-1)]
        if 1 in temp:
            index = temp.index(1)
            for i in range(m-index):
                obstacleGrid[i][-1] = 1
        dp = [[1-obstacleGrid[i][j] for j in range(n)] for i in range(m)]
        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                if dp[i][j] != 0:
                    dp[i][j] = dp[i+1][j] + dp[i][j+1]
        return dp[0][0]
```

## leetcode solution
```
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1: return 0
        obstacleGrid[0][0] = 1
        for i in range(1, m):
            obstacleGrid[i][0] = int(obstacleGrid[i][0] == 0 and obstacleGrid[i-1][0] == 1)
        for i in range(1, n):
            obstacleGrid[0][i] = int(obstacleGrid[0][i] == 0 and obstacleGrid[0][i-1] == 1)
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 0:
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
                else:
                    obstacleGrid[i][j] = 0
        return obstacleGrid[-1][-1]
```
