## Leetcode
```
class Solution:
    def missingNumber(self, nums):
        n = len(nums)
        nums.sort()
        for i in range(n):
            if i != nums[i]:
                return i
        return n
```
```
class Solution:
    def missingNumber(self, nums):
        num_set = set(nums)
        n = len(nums) + 1
        for i in range(n):
            if i not in num_set:
                return i
```

#### Binary Search
```class Solution:
    def missingNumber(self, nums):
        nums.sort()
        n = len(nums)
        l, r = 0, n
        while l < r:
            mid = (l + r) // 2
            if nums[mid] > mid:
                r = mid
            else:
                l = mid + 1
        return l
```

#### Bit Manipulation
```
class Solution:
    def missingNumber(self, nums):
        missing = len(nums)
        for i, num in enumerate(nums):
            missing ^= i ^ num
        return missing
```

#### Math
```
class Solution:
    def missingNumber(self, nums):
        n = len(nums)
        expected = (1 + n) * n // 2
        return expected - sum(nums)
```
