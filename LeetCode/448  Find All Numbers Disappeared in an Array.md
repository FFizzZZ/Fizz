## Leetcode
```
class Solution(object):
    def findDisappearedNumbers(self, nums):
        for i in nums:
            index = abs(i) - 1
            if nums[index] > 0:
                nums[index] *= -1
        return [i + 1 for i in range(len(nums)) if nums[i] > 0]
```
