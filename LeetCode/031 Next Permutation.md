```
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        for i in range(len(nums) - 1, 0, - 1):
            if nums[i] > nums[i - 1]:
                for j in range(len(nums) - 1, i - 1, -1):
                    if nums[j] > nums[i - 1]:
                        nums[j], nums[i - 1] = nums[i - 1], nums[j]
                        self.reverse(nums, i, len(nums) - 1)
                        return
        self.reverse(nums, 0, len(nums) - 1)
        
    def reverse(self, nums, l, r):
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
```
