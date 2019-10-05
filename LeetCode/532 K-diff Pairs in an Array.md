## Leetcode
```
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k == 0:
            d = collections.Counter(nums)
            return sum(x > 1 for x in d.values())
        elif k < 0: 
            return 0
        else:
            s = set(nums)
            return sum(x + k in s for x in s)
```
