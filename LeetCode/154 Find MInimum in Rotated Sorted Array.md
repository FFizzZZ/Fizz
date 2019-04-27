## Binary Search
```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] < nums[-1]: return nums[0]
        left, right = 0, len(nums) - 1
        while right - left > 1:
            mid = (left + right) // 2
            if nums[0] == nums[mid] and nums[-1] == nums[mid]:
                return min(nums)
            if nums[mid] >= nums[0]:
                left = mid
            elif nums[mid] <= nums[-1]:
                right = mid
        return nums[right]
```
