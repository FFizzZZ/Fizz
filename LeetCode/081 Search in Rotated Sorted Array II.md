```
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if not nums: return False
        n = len(nums)
        l, r = 0, n - 1
        while l < r:
            mid = (l + r) // 2
            val = nums[mid]
            if val < nums[r]:
                r = mid
            elif val > nums[r]:
                l = mid + 1
            else:
                if nums[r] < nums[r - 1]: break   # in order to find the index of the turning point
                r -= 1
        if r == 0:
            l, r = 0, n - 1
        else:
            l, r = (0, r - 1) if nums[0] <= target else (r, n - 1)
        while l <= r:
            mid = (l + r) // 2
            val = nums[mid]
            if val == target:
                return True
            elif val < target:
                l = mid + 1
            else:
                r = mid - 1
        return False
```

```
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            val = nums[mid]
            if nums[mid] == target:
                return True
            if nums[l] == nums[mid]:          # pay attention to this one!
                l += 1
            elif nums[l] < nums[mid]:
                if nums[l] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
        return False
```
