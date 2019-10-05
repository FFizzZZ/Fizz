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
