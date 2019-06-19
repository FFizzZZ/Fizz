```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums: return -1
        if len(nums) == 1: return max(target==nums[0], 0) - 1
        if target == nums[0]: return 0
        if target == nums[-1]: return len(nums) - 1
        if nums[-1] < target < nums[0]:
            return -1
        elif target < nums[-1]:
            for i in range(len(nums)-2, -1, -1):
                if target > nums[i]:
                    return -1
                elif target == nums[i]:
                    return i
        elif target > nums[0]:
            for i in range(1, len(nums)):
                if target < nums[i]:
                    return -1
                elif target == nums[i]:
                    return i
        return -1
```

----------------------
## find the minimum and then use binary search
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums: return -1
        if nums[0] < nums[-1]: r = 0
        else:
            l, r = 0, len(nums) - 1
            while l < r:
                mid = (l + r) // 2
                val = nums[mid]
                if val >= nums[0]:
                    l = mid + 1
                else:
                    r = mid
        if r == 0:
            l, r = 0, len(nums) - 1
        elif target >= nums[0]:
            l, r = 0, r - 1
        else:
            l, r = r, len(nums) - 1
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
another version from others
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums: return -1
        n = len(nums)
        l, r = 0, n - 1
        if nums[l] > nums[r]:
            while l < r:
                mid = (l + r) // 2
                val = nums[mid]
                if val >= nums[0]:
                    l = mid + 1
                else:
                    r = mid
        l, r, temp = 0, n - 1, l
        while l <= r:
            mid = (l + r) // 2
            realmid = (mid + temp) % n
            val = nums[realmid]
            if val == target:
                return realmid
            elif val < target:
                l = mid + 1
            else:
                r = mid - 1
        return -1
```
                

## change some elements into inf or -inf
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums: return -1
        if target == nums[0]: return 0
        elif target > nums[0]:
            for i in range(len(nums)-1, -1, -1):
                if nums[i] < nums[0]:
                    nums[i] = float('inf')
                else: break
        else:
            for i in range(len(nums)):
                if nums[i] > nums[-1]:
                    nums[i] = float('-inf')
                else: break
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

## 数组从任意位置劈开后，至少有一半是有序的
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums: return -1
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            val = nums[mid]
            if val == target:
                return mid
            if nums[l] <= nums[mid]:
                if nums[l] <= target <= nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
        return -1
```
