## Leetcode
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l = float('inf')
        ans = 0
        for i in range(len(prices)):
            if prices[i] < l:
                l = prices[i]
            if prices[i] - l > ans:
                ans = prices[i] - l
        return ans
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
