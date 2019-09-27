## Leetcode
##### Suppose we make all elements equal to x after m moves, so we have sum(nums) + m * (n - 1) = n * x.  
##### On the other hand, we have x = min(nums) + m.
##### As a result, we have m = sum(nums) - len(nums) * min(nums).
```
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return sum(nums) - len(nums) * min(nums)
```

#### Here is another more amazing way to consider this problem. Every steps we can think that there is one element decreasing 1. So the minimum moves we need is (nums[0] - min) + (nums[1] - min) + ... + (nums[-1] - min) = sum(nums) - n * min. Cool!
