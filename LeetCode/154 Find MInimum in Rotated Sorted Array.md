## Binary Search
left指向前面的数组，right指向后面的数组。当mid, left, right的数值相同时，无法判断。
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
```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            val = nums[mid]
            if val == nums[-1]:
                return min(nums)
            if val > nums[-1]:
                l = mid + 1
            else:
                r = mid
        return nums[r]
```
