```
class Solution(object):
    def maxProfit(self, prices, fee):
        buy = float('-inf')
        sell = 0
        for p in prices:
            buy, sell = max(buy, sell - p), max(sell, buy + p - fee)
        return sell
```

## Leetcode
```
class Solution:
    def maxProfit(self, prices, fee):
        n = len(prices)
        if n < 2: return 0
        ans = 0
        low = prices[0]
        for price in prices:
            if price < low:
                low = price
            elif price - low - fee > 0:
                ans += price - low - fee
                low = price - fee
        return ans
```
