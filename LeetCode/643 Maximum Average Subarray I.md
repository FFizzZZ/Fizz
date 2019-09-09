```
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n = len(nums)
        p = [0] * (n + 1)
        for i in range(n):
            p[i + 1] = p[i] + nums[i]
        ans = p[k]
        for i in range(k, n + 1):
            tmp = p[i] - p[i - k]
            if tmp > ans:
                ans = tmp
        return ans / k
```
