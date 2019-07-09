```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        index = -1
        for i in range(len(nums)):
            if nums[i] != 0:
                index += 1
                if index < i:
                    nums[index], nums[i] = nums[i], nums[index]
```
## Leetcode
```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        index = -1
        for i in range(len(nums)):
            if nums[i] != 0:
                index += 1
                nums[index] = nums[i]
        for i in range(index + 1, len(nums)):
            nums[i] = 0
```
