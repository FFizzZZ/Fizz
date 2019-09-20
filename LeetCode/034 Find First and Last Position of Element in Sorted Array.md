```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        left = bisect.bisect_left(nums, target)
        if left == n or nums[left] != target:
            return [-1, -1]
        return [left, bisect.bisect_right(nums, target) - 1]
```
 
```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        l, r = 0, n
        while l < r:
            mid = (l + r) // 2
            val = nums[mid]
            if val < target:
                l = mid + 1
            else:
                r = mid
        if r == n or nums[r] != target:
            return [-1, -1]
        start = l
        l, r = 0, n
        while l < r:
            mid = (l + r) // 2
            val = nums[mid]
            if val <= target:
                l = mid + 1
            else:
                r = mid
        return [start, r - 1]
```
## Leetcode
#### Binary Search
```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = self.insert(nums, target, True)
        if left == len(nums) or nums[left] != target:
            return [-1, -1]
        return [left, self.insert(nums, target, False) - 1]
        
    def insert(self, nums, target, left):
        l, r = 0, len(nums)
        while l < r:
            mid = (l + r) // 2
            val = nums[mid]
            if val > target or (left and target == val):
                r = mid
            else:
                l = mid + 1
        return l
```

#### Divide and Conquer
```
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums: return [-1, -1]
        def search(lo, hi):
            if nums[lo] == target == nums[hi]:
                return [lo, hi]
            if nums[lo] <= target <= nums[hi]:
                mid = (lo + hi) // 2
                l, r = search(lo, mid), search(mid+1, hi)
                return max(l, r) if -1 in l+r else [l[0], r[1]]
            return [-1, -1]
        return search(0, len(nums)-1)
```

```
class Solution:
    def searchRange(self, nums, target):
        def search(n):
            lo, hi = 0, len(nums)
            while lo < hi:
                mid = (lo + hi) // 2
                if nums[mid] >= n:
                    hi = mid
                else:
                    lo = mid + 1
            return lo
        lo = search(target)
        return [lo, search(target+1)-1] if target in nums[lo:lo+1] else [-1, -1]
```











