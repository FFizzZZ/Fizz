## Leetcode
```
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        return self.f(nums, 0, len(nums) - 1, {}) >= 0
    def f(self, nums, l, r, d):
        if l == r:
            return nums[l]
        if (l, r) in d:
            return d[(l, r)]
        a = nums[l] - self.f(nums, l + 1, r, d)
        b = nums[r] - self.f(nums, l, r - 1, d)
        val = max(a, b)
        d[(l, r)] = val
        return val
```
