## Leetcode
```
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        l = len(prices)
        if l == 0: return 0
        if k >= l // 2:
            profits = 0
            for i in range(1, l):
                diff = prices[i] - prices[i - 1]
                if diff > 0:
                    profits += diff
            return profits
        pre = [0] * l
        cur = [0] * l
        for i in range(k):
            tmp = -prices[0]
            for j in range(1, l):
                cur[j] = max(cur[j - 1], tmp + prices[j])
                tmp = max(tmp, pre[j] - prices[j])
            pre = cur[:]
        return cur[-1]
```
