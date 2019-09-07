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
