```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums: return -1
        l, r = 0, len(nums) - 1
        left, right = nums[0], nums[-1]
        while l <= r:
            mid = (l + r) // 2
            val = nums[mid]
            if val == target:
                return mid
            if val >= left:
                if left <= target < val:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if val < target <= right:
                    l = mid + 1
                else:
                    r = mid - 1
                if target > right:
                    r = mid - 1
        return -1
```

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
        n = len(nums)
        l, r = 0, n - 1
        while l < r:
            mid = (l + r) // 2
            val = nums[mid]
            if val > nums[r]:
                l = mid + 1
            else:
                r = mid
        shift = r
        l, r = 0, n - 1
        while l <= r:
            mid = (l + r) // 2
            real_mid = (mid + shift) % n
            val = nums[real_mid]
            if val == target:
                return real_mid
            if val < target:
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
改进：在二分的时候改变mid的值
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            val= nums[mid]
            if val == target:
                return mid
            if (nums[mid] < nums[0]) != (target < nums[0]):
                val = float('-inf') if target < nums[0] else float('inf')
            if val < target:
                l = mid + 1
            else:
                r = mid - 1
        return -1
```

## 判断target和mid是否在同一段上
```
class Solution:
    def search(self, nums, target):
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            val = nums[mid]
            if val == target:
                return mid
            if (val < nums[0]) == (target < nums[0]):
                if val < target:
                    l = mid + 1
                else:
                    r = mid - 1
            elif target < nums[0]:
                l = mid + 1
            else:
                r = mid - 1
        return -1
```

## 数组从任意位置劈开后，至少有一半是有序的
```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if target == nums[mid]:
                return mid
            if nums[0] <= nums[mid]:
                if nums[0] <= target <= nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid] <= target <= nums[-1]:
                    l = mid + 1
                else:
                    r = mid - 1
        return -1
```
简化
```
class Solution:
    def search(self, nums, target):
        lo, hi = 0, len(nums) - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if (nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]):
                lo = mid + 1
            else:
                hi = mid
        return lo if target in nums[lo:lo+1] else -1
```
