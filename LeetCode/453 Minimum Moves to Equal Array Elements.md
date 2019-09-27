## Leetcode
##### Suppose we make all elemente equal to x after m moves, so we have sum(nums) + m * (n - 1) = n * x.  
On the other hand, we have x = min(nums) + m.

```
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return sum(nums) - len(nums) * min(nums)
```
