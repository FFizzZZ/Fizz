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
