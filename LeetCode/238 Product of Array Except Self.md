## Leetcode
```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        l, r, ans = [0] * n, [0] * n, [0] * n
        l[0], r[-1] = 1, 1
        for i in range(1, n):
            l[i] = l[i - 1] * nums[i - 1]
            r[n - 1 - i] = r[n - i] * nums[n - i]
        for i in range(n):
            ans[i] = l[i] * r[i]
        return ans
```
#### Optimized Verison
```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1] * n
        for i in range(1, n):
            ans[i] = nums[i - 1] * ans[i - 1]
        r = nums[-1]
        for i in range(n - 2, -1, -1):
            ans[i] *= r
            r *= nums[i]
        return ans
```
