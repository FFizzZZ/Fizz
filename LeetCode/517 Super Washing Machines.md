## Leetcode
```
class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        total = sum(machines)
        if total % len(machines) != 0: return -1
        avg = total // len(machines)
        cnt = Max = 0
        for load in machines:
            cnt += load - avg
            Max = max(Max, abs(cnt), load - avg)
        return Max
```
