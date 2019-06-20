## Binary Search
left指向前面的数组，right指向后面的数组。当mid, left, right的数值相同时，无法判断。
```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            val = nums[mid]
            if val > nums[r]:
                l = mid + 1
            elif val < nums[r]:
                r = mid
            else:
                # add the following one can make sure we find the index of the turning point.
                # if nums[r] < nums[r - 1]: break
                r -= 1
        return nums[r]
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

