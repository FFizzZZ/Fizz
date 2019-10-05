```
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return sum(val for idx, val in enumerate(nums) if idx % 2 == 0)
```
