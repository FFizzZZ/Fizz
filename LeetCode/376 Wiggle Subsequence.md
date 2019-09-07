## Leetcode

#### Dynamic Programming
```
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2: return n
        up = [1] * n
        down = [1] * n
        for j in range(1, n):
            for i in range(j):
                if nums[i] < nums[j]:
                    up[j] = max(up[j], down[i] + 1)
                elif nums[i] > nums[j]:
                    down[j] = max(down[j], up[i] + 1)
        return max(up[-1], down[-1])
```
