## leetcode
```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        zero, second = -1, len(nums)
        for i in range(len(nums)):
            if i == second: break
            while nums[i] == 2 and i < second:
                second -= 1
                nums[i], nums[second] = nums[second], nums[i]
            if nums[i] == 0:
                zero += 1
                nums[i], nums[zero] = nums[zero], nums[i]
```
```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        n = len(nums)
        zero, second = 0, n - 1
        for i in range(n):
            if i > second: break
            while nums[i] == 2 and i < second:
                nums[i], nums[second] = nums[second], nums[i]
                second -= 1
            while nums[i] == 0 and i > zero:
                nums[i], nums[zero] = nums[zero], nums[i]
                zero += 1
```
```
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        x, y, z = -1, -1, -1
        for i in range(len(nums)):
            if nums[i] == 0:
                x += 1
                y += 1
                z += 1
                nums[z] = 2
                nums[y] = 1
                nums[x] = 0
            elif nums[i] == 1:
                y += 1
                z += 1
                nums[z] = 2
                nums[y] = 1
            else:
                z += 1
                nums[z] = 2
```

        
            
