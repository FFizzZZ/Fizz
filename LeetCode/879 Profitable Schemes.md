## Leetcode
#### Dynamic Programming
```
class Solution:
    def profitableSchemes(self, G: int, P: int, group: List[int], profit: List[int]) -> int:
        dp = [[0] * (G + 1) for _ in range(P + 1)]
        dp[0][0] = 1
        for p, g in zip(profit, group):
            for i in range(P, - 1, -1):
                tmp = min(P, i + p)
                for j in range(G - g, - 1, -1):
                    dp[tmp][j + g] += dp[i][j]
        return sum(dp[-1]) % (10 ** 9 + 7)
```
        
#### Slightly Faster
```
class Solution:
    def profitableSchemes(self, G: int, P: int, group: List[int], profit: List[int]) -> int:
        dp = [[0] * (G + 1) for _ in range(P)]
        dp[0][0] = 1
        for p, g in zip(profit, group):
            for i in range(P - p - 1, - 1, -1):
                for j in range(G - g, - 1, -1):
                    dp[i + p][j + g] += dp[i][j]
        less = sum(sum(row) for row in dp)
        dp = [0] * (G + 1)
        dp[0] = 1
        for g in group:
            for i in range(G, g - 1, -1):
                dp[i] += dp[i - g]
        total = sum(dp)
        return (total - less) % (10 ** 9 + 7)
```
