## leetcode
```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zero, second = -1, len(nums)
        for i in range(second):
            while nums[i] == 2 and i < second:
                second -= 1
                nums[i], nums[second] = nums[second], nums[i]
            while nums[i] == 0 and i > zero:
                zero += 1
                nums[i], nums[zero] = nums[zero], nums[i]
```

## some change by myself
```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        zero, second = -1, len(nums)
        i = 0
        while i < second:
            while nums[i] == 2 and i < second:
                second -= 1
                nums[i], nums[second] = nums[second], nums[i]
            if nums[i] == 0 and i > zero:
                zero += 1
                nums[i], nums[zero] = nums[zero], nums[i]
            i += 1
```
        
            
