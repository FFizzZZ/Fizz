## Leetcode
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            val = nums[mid]
            if val == target:
                return mid
            elif val < target:
                l = mid + 1
            else:
                r = mid - 1
        return -1
```
