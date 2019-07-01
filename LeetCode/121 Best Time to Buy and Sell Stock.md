## Leetcode
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
#### Kadane's Algorithm
I think the idea behind this algorithm is almost the same as the solution given by Leetcode
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxCur, maxSoFar = 0, 0
        for i in range(1, len(prices)):
            maxCur += prices[i] - prices[i - 1]
            maxCur = max(0, maxCur)
            maxSoFar = max(maxCur, maxSoFar)
        return maxSoFar
```
