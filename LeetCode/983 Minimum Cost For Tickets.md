## Leetcode
#### Dynamic Programming (Day Variant)
```
class Solution:
    def mincostTickets(self, days, costs):
        day = set(days)
        dp = [0] * 396
        for i in range(max(day), 0, -1):
            if i in day:
                dp[i] = min(dp[i + 1] + costs[0], dp[i + 7] + costs[1], dp[i + 30] + costs[2])
            else:
                dp[i] = dp[i + 1]
        return dp[1]
```

```
class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        n = days[-1]
        dp = [-1] * (n + 1)
        dp[0] = 0
        for d in days:
            dp[d] = 0
        c1, c2, c3 = costs
        for i in range(1, n + 1):
            if dp[i] < 0:
                dp[i] = dp[i - 1]
            else:
                dp[i] = min(dp[i - 1] + c1,
                           dp[max(i - 7, 0)] + c2,
                           dp[max(i - 30, 0)] + c3)
        return dp[n]
```

#### Dynamic Programming (Window Variant)
```
class Solution:
    def mincostTickets(self, days, costs):
        n = len(days)
        durations = [1, 7, 30]
        dp = [0] * n
        for i in range(n - 1, -1, -1):
            index = i + 1
            ans = float('inf')
            for c, d in zip(costs, durations):
                while index < n and days[index] < days[i] + d:
                    index += 1
                if index < n:
                    ans = min(ans, dp[index] + c)
                else:
                    ans = min(ans, c)
            dp[i] = ans
        return dp[0]
```


