## Leetcode
```
class Solution:
    def partitionDisjoint(self, nums):
        n = len(nums)
        left, right = [0] * n, [0] * n
        tmp1, tmp2 = float('-inf'), float('inf')
        for i in range(n):
            val1, val2 = nums[i], nums[n - 1 - i]
            tmp1 = max(val1, tmp1)
            tmp2 = min(val2, tmp2)
            left[i], right[n - 1 - i] = tmp1, tmp2
        for i in range(n - 1):
            if left[i] <= right[i + 1]:
                return i + 1
```
