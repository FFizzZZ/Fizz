## Leetcode

```
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        for i in range(len(nums) - 1, 1, -1):
            l, r = 0, i - 1
            val = nums[i]
            while l < r:
                if nums[l] + nums[r] > val:
                    ans += r - l
                    r -= 1
                else:
                    l += 1
        return ans
```

