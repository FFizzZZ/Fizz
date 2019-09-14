## Leetcode
```
class Solution:
    def wiggleSort(self, nums):
        nums.sort()
        n = (len(nums) + 1) // 2
        nums[::2], nums[1::2] = nums[:n][::-1], nums[n:][::-1]
```
