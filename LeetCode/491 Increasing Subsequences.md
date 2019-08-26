```
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
```
        
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
        
```
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:        
        #dp的思路体现为，以dp(i)为起点的递增子序列为
        # dp(i) = dp(k) + nums[i]，其中k是所有在i之后的比i大于等于的数
        results = set()
        if len(nums) == 0:
            return []
        dp = [[[x]] for x in nums]
        for i in range(len(nums) - 2, -1, -1):
            for j in range(i + 1, len(nums)):
                if nums[j] >= nums[i] and (j == i + 1 or nums[j - 1] != nums[j]):
                    for one in dp[j]:
                        nextone = [nums[i]] + one
                        dp[i].append(nextone)
                        results.add(tuple(nextone))
        return results      #leetcode代码中自动执行了类型转换
```
                
