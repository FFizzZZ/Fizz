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
