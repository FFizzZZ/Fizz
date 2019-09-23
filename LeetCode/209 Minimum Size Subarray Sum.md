## Leetcode



#### Using two pointers, O(n)
```
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        ans = float('inf')
        left = 0
        cur = 0
        for idx, val in enumerate(nums):
            cur += val
            while cur >= s:
                ans = min(ans, idx - left + 1)
                cur -= nums[left]
                left += 1
        return ans if ans < float('inf') else 0
```
