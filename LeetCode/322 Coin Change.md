```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount < 1: return 0
        d = {}
        return self.f(coins, amount, d)
    def f(self, coins, remain, d):
        if remain == 0: return 0
        if remain in d: return d[remain]
        ans = remain + 1
        for x in coins:
            if x <= remain:
                temp = self.f(coins, remain - x, d)
                if temp >= 0: 
                    temp += 1
                    if temp < ans:
                        ans = temp
        if ans == remain + 1: ans = -1
        d[remain] = ans
        return ans
```
            
            
## Leetcode
#### permutation
```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for x in coins:
                if x <= i:
                    temp = dp[i - x] + 1
                    if temp < dp[i]:
                        dp[i] = temp
        if dp[-1] > amount:
            return -1
        else:
            return dp[-1]
```
#### combination
```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for x in coins:
            for i in range(x, amount + 1):
                temp = dp[i - x] + 1
                if temp < dp[i]:
                    dp[i] = temp
        return -1 if dp[-1] > amount else dp[-1]

```
#### FASTEST
```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        def f(cur, need, idx):
            nonlocal ans
            val = coins[idx]
            times, remain = divmod(need, val)
            tmp = times + cur
            if remain == 0:
                if tmp < ans: 
                    ans = tmp
                return
            if idx == len(coins) - 1: return
            if tmp >= ans: return
            for num in range(times, -1, -1):
                f(cur + num, need - num * val, idx + 1)
        coins.sort(reverse = True)
        ans = float('inf')
        f(0, amount, 0)
        return ans if ans < float('inf') else -1
```


