class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        dp = [[[x]] for x in nums]
        
        for j in range(1, n)
            for i in range(j - 1, -1, -1):
                if nums[i] == nums[j]:
                    for x in dp[i]:
                        dp[j].append(x + [nums[j]])
                    break
                elif nums[i] < nums[j]:
                    for x in dp[i]:
                        dp[j].append(x + [nums[j]])
        ans = []
        for x in dp:
            ans.extend(x[1:])
        return sorted(ans)
        
        
## Leetcode
```
class Solution:
    def findSubsequences(self, nums):
        subs = {()}
        for num in nums:
            subs.update({sub + (num,)
                     for sub in subs
                     if not sub or sub[-1] <= num})
        return [sub for sub in subs if len(sub) >= 2]
```
        
        
                
