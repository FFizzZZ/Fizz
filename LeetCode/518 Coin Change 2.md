```
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1
        for x in coins:
            for i in range(amount - x + 1):
                dp[i + x] += dp[i]
        return dp[-1]
```
