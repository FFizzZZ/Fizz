```
class NumArray:
    def __init__(self, nums: List[int]):
        n = len(nums)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]
        self.prefix = prefix

    def sumRange(self, i: int, j: int) -> int:
        return self.prefix[j + 1] - self.prefix[i]
```
