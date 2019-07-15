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
```
class Solution(object):
    def findDisappearedNumbers(self, nums):
        for i in range(len(nums)):
            while nums[i] != i + 1 and nums[nums[i] - 1] != nums[i]:
                temp = nums[i]
                nums[i] = nums[temp - 1]
                nums[temp - 1] = temp
        return [i + 1 for i in range(len(nums)) if nums[i] != i + 1]
```
