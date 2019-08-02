## Leetcode
```
class Solution:
    def wiggleSort(self, nums):
        nums.sort()
        half = len(nums[::2])
        nums[::2], nums[1::2] = nums[:half], nums[half:]   
```
