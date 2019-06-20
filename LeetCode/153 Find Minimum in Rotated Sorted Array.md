```
class Solution(object):
    def findMin(self, nums):
        left, right = 0, len(nums) - 1
        if nums[right] > nums[0]:
            return nums[0]
        while right > left:
            mid = (right + left) // 2
            if nums[mid] >= nums[0]:
                left = mid + 1
            else:
                right = mid
        return nums[right]
```

## Binary Search
```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            val = nums[mid]
            if val > nums[-1]:
                l = mid + 1
            else:
                r = mid
        return nums[r]
```

```
class Solution(object):
    def findMin(self, nums):
        if len(nums) == 1:
            return nums[0]
        left, right = 0, len(nums) - 1
        if nums[right] > nums[0]:
            return nums[0]
        while right >= left:
            mid = (right + left) // 2
            if nums[mid] > nums[mid + 1]:
                return nums[mid + 1]
            if nums[mid - 1] > nums[mid]:
                return nums[mid]
            if nums[mid] > nums[0]:
                left = mid + 1
            else:
                right = mid - 1
```
