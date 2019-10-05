```
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        total = len(timeSeries) * duration
        end = 0
        for time in timeSeries:
            if time < end:
                total -= end - time
            end = time + duration
        return total
```

## Leetcode
```
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        n = len(timeSeries)
        if n == 0: return 0
        total = 0
        pre = timeSeries[0]
        for time in timeSeries:
            total += min(time - pre, duration)
            pre = time
        return total + duration
```
