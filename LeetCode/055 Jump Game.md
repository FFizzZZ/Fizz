```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        index = 0
        for i, v in enumerate(nums):
            if i > index: return False
            if i + v > index:
                index = i + v
        return True
```
## Leetcode
```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        index = len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            if i + nums[i] >= index:
                index = i
        return index == 0
```

