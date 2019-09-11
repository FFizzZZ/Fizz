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
        end = [float('inf')] * n
        candidate = [[] for _ in range(n)]
        cnt = [0] * n
        for x in nums:
            index = bisect.bisect_left(end, x)
            end[index] = x
            if index == 0:
                count = 1
            else:
                while candidate[index - 1][0][0] >= x:
                    cnt[index - 1] -= candidate[index - 1].pop(0)[1]
                count = cnt[index - 1]
            cnt[index] += count
            candidate[index].append((x, count))
        for i in range(n - 1, -1, -1):
            if cnt[i] > 0:
                return cnt[i]
        return 0
```
        
        
        
     
 
