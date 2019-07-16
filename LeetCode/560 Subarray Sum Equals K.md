## Leetcode
#### cummulative sum
```
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        n = len(nums)
        cumsum = [0] * (n + 1)
        s = 0
        for i in range(n):
            s += nums[i]
            cumsum[i + 1] = s
        for start in range(n):
            for end in range(start + 1, n + 1):
                if cumsum[end] - cumsum[start] == k:
                    count += 1
        return count
```
