## Leetcode
#### Dynamic Programming
```
class Solution(object):
    def findNumberOfLIS(self, nums):
        n = len(nums)
        if n <= 1: return n
        tails = [1] * n
        cnt = [1] * n
        for j in range(n):
            for i in range(j):
                if nums[i] < nums[j]:
                    if tails[i] >= tails[j]:
                        tails[j] = tails[i] + 1
                        cnt[j] = cnt[i]
                    elif tails[i] + 1 == tails[j]:
                        cnt[j] += cnt[i]
        length = max(tails)
        return sum(c for i, c in enumerate(cnt) if tails[i] == length)
```
```
class Solution(object):
    def findNumberOfLIS(self, nums):
        dp = [[1, 1] for i in range(len(nums))]
        max_for_all = 1
        for i, num in enumerate(nums):
            max_len, count = 1, 1
            for j in range(i):
                if nums[j] < num:
                    if dp[j][0] >= max_len:
                        max_len = dp[j][0] + 1
                        count = dp[j][1]
                    elif dp[j][0] == max_len - 1:
                        count += dp[j][1]
            dp[i] = [max_len, count]
            max_for_all = max(max_len, max_for_all)
        return sum([item[1] for item in dp if item[0] == max_for_all])
```
#### FASTEST
```
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        tails = [float("inf")] * n
        candidates = [[] for _ in range(n)]
        counts = [0] * n
        for x in nums:
            idx = bisect.bisect_left(tails, x)
            tails[idx] = x
            if idx == 0:
                cnt = 1
            else:
                while candidates[idx - 1][0][0] >= x:
                    counts[idx - 1] -= candidates[idx - 1].pop(0)[1]
                cnt = counts[idx - 1]
            counts[idx] += cnt
            candidates[idx].append((x, cnt))
        for i in range(n - 1, -1, -1):
            if counts[i] > 0:
                return counts[i]
        return 0
```
        
        
        
     
 
