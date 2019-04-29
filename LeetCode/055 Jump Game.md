```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        temp = 0
        end = 0
        for i in range(len(nums)-1):
            if temp >= i:
                temp = max(temp, nums[i] + i)
            if i == end:
                end = temp
        return True if temp >= len(nums) - 1 else False
```
