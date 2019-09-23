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

#### Using Binary Search, O(nlogn)
```
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        n = len(nums)
        if n == 0: return 0
        ans = float("inf")
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]
        for i in range(1, n + 1):
            to_find = s + prefix[i - 1]
            idx = bisect.bisect_left(prefix, to_find)
            if idx != n + 1:
                ans = min(ans, idx - i + 1)
        return ans if ans < float('inf') else 0
```
