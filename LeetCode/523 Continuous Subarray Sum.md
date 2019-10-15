## Leetcode
```
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        d = {0: -1}
        cur = 0
        for idx, val in enumerate(nums):
            cur += val
            if k != 0: cur %= k
            pre = d.get(cur, None)
            if pre != None:
                if idx - pre > 1: return True
            else:
                d[cur] = idx
        return False
```
