## Leetcode
#### Dynamic Programming
```
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])
        hp = [[float("inf")] * (n + 1) for _ in range(m + 1)]
        hp[m][n - 1] = hp[m - 1][n] = 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j]
                hp[i][j] = 1 if need <= 0 else need
        return hp[0][0]
```

##### Optimized Version
```
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m, n = len(dungeon), len(dungeon[0])
        dp = [float("inf")] * (n + 1)
        dp[n - 1] = 1
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                need = min(dp[j], dp[j + 1]) - dungeon[i][j]
                dp[j] = need if need > 0 else 1
        return dp[0]
```
    

        



            
            
