## Leetcode
#### mark visited element as negative
```
class Solution(object):
    def findDisappearedNumbers(self, nums):
        for i in nums:
            index = abs(i) - 1
            if nums[index] > 0:
                nums[index] *= -1
        return [i + 1 for i in range(len(nums)) if nums[i] > 0]
```
similar idea
```
class Solution(object):
    def findDisappearedNumbers(self, nums):
        N = len(nums)
        for i in range(len(nums)):
            nums[(nums[i]%N)-1] += N
        return [i+1 for i in range(len(nums)) if nums[i]<=N]
```
#### assign each element to its index
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
