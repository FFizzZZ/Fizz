## Leetcode
```
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        cur, total, index = 0, 0, 0
        for i in range(len(gas)):
            cur += gas[i] - cost[i]
            if cur < 0:
                total += cur
                cur = 0
                index = i + 1
        if total + cur < 0:
            return -1
        else:
            return index
```
