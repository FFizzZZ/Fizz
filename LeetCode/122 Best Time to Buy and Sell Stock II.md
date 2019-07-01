


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
The key point is we need to consider every peak immediately following a valley to maximize the profit. In case we skip one of the peaks (trying to obtain more profit), we will end up losing the profit over one of the transactions leading to an overall lesser profit.
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
#### Simple One Pass
This solution follows the logic used in Approach 2 itself, but with only a slight variation. In this case, instead of looking for every peak following a valley, we can simply go on crawling over the slope and keep on adding the profit obtained from every consecutive transaction.
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                ans += prices[i] - prices[i - 1]
        return ans
```
