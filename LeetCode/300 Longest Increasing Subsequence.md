```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums: return 0
        n = len(nums)
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    tmp = dp[j] + 1
                    if tmp > dp[i]:
                        dp[i] = tmp
        return max(dp)
```
