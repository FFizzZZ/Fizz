```
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        first = second = 0
        for i in range(2, len(cost) + 1):
            first, second = second, min(first + cost[i - 2], second + cost[i - 1])
        return second
```

## Leetcode
```
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        f1 = f2 = 0
        for x in reversed(cost):
            f1, f2 = x + min(f1, f2), f1
        return min(f1, f2)
```
