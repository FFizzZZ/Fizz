```
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        m = max(nums)
        if all(m >= 2 * x for x in nums if x != m):
            return nums.index(m)
        return -1
```

##
```
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        Max = -1
        second = -1
        idx = 0
        for i, x in enumerate(nums):
            if x >= Max:
                second = Max
                Max = x
                idx = i
            elif x > second:
                second = x
        if Max < 2 * second:
            return -1
        return idx
```
