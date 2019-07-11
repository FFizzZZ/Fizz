```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n < 2: return 0
        s1, s2, b = 0, 0, -prices[0]
        for i in range(1, n):
            b, s1, s2 = max(s1 - prices[i], b), s2, max(s2, prices[i] + b)
        return s2
```

```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n < 2: return 0
        s1, s2, b = 0, 0, float('-inf')
        for i in prices:
            b, s1, s2 = max(s1 - i, b), s2, max(s2, i + b)
        return s2
```

## Leetcode
#### Dynamic Programming
```
class Solution:
    def maxProfit(self, prices):
        if len(prices) < 2:
            return 0
        sell, buy, prev_sell, prev_buy = 0, -prices[0], 0, 0
        for price in prices:
            prev_buy = buy
            buy = max(prev_sell - price, prev_buy)
            prev_sell = sell
            sell = max(prev_buy + price, prev_sell)
        return sell
```
```
class Solution:
    def maxProfit(self, prices):
        free = 0
        have = cool = float('-inf')
        for p in prices:
            free, have, cool = max(free, cool), max(have, free - p), have + p
        return max(free, cool)
```
