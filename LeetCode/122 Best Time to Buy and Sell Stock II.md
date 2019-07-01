


## Leetcode
#### Brute Force: Time Limit Exceed!
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return self.f(0, prices)
    def f(self, start, prices):
        if start == len(prices):
            return 0
        max = 0
        for i in range(start, len(prices)):
            maxprofit = 0
            for j in range(i + 1, len(prices)):
                if prices[i] < prices[j]:
                    profit = self.f(j + 1, prices) + prices[j] - prices[i]
                    if profit > maxprofit:
                        maxprofit = profit
            if maxprofit > max:
                    max = maxprofit
        return max
```

#### Peak-Valley Approach
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 0
        l = len(prices)
        ans = 0
        while i < l - 1:
            while i < l - 1 and prices[i] >= prices[i + 1]:
                i += 1
            valley = prices[i]
            while i < l - 1 and prices[i] <= prices[i + 1]:
                i += 1
            peak = prices[i]
            ans += peak - valley
        return ans            
```
