## Leetcode
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        hold1, hold2 = float('-inf'), float('-inf')
        release1, release2 = 0, 0
        for i in prices:
            release2 = max(release2, hold2 + i)
            hold2 = max(hold2, release1 - i)
            release1 = max(release1, hold1 + i)
            hold1 = max(hold1, -i)
        return release2
```
#### Dynamic Programming
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        K = 2
        l = len(prices)
        f = [[0] * l for _ in range(K + 1)]
        for i in range(1, K + 1):
            temp = f[i - 1][0] - prices[0]
            for j in range(1, l):
                f[i][j] = max(f[i][j - 1], prices[j] + temp)
                temp = max(temp, f[i - 1][j] - prices[j])
        return f[-1][-1]
```
