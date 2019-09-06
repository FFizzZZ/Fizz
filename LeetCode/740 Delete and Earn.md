## Leetcode
```
class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        d = collections.Counter(nums)
        pre = None
        avoid = using = 0
        for k in sorted(d):
            if k - 1 != pre:
                avoid, using = max(avoid, using), k * d[k] + max(avoid, using)
            else:
                avoid, using = max(avoid, using), k * d[k] + avoid
            pre = k
        return max(avoid, using) 
```
