## Leetcode
```
from bisect import bisect_right
class Solution:
    def reversePairs(self, nums):
        if not nums: return 0
        seen = []
        res = 0
        for x in nums:
            res += len(seen) - bisect_right(seen, 2*x)
            idx = bisect_right(seen, x)
            seen[idx:idx] = [x]
        return res
```
