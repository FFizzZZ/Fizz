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

```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        index = bisect.bisect_left(nums, target)
        try:
            if nums[index] == target:
                return index
            else:
                return -1
        except:
            return -1
```
