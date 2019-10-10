## Leetcode
```
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        cur = 0
        for idx, val in enumerate(nums):
            if cur == total - cur - val:
                return idx
            cur += val
        return -1
```
