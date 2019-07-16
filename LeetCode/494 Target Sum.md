```
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        ans = self.f(0, nums, {})
        return sum([x == S for x in ans])
    def f(self, index, nums, d):
        if index == len(nums):
            return [0]
        if index in d: return d[index]
        val = nums[index]
        ans = []
        for i in self.f(index + 1, nums, d):
            ans.extend([val + i, -val + i])
        d[index] = ans
        return ans
```
        
```
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        self.count = 0
        self.f(nums, 0, 0, S)
        return self.count
    def f(self, nums, i, s, S):
        if i == len(nums):
            if s == S:
                self.count += 1
        else:
            self.f(nums, i + 1, s + nums[i], S)
            self.f(nums, i + 1, s - nums[i], S)
```
```
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        s = sum(nums)
        if s < S or (s + S) & 1:
            return 0
        else:
            return self.f(nums, (s + S) >> 1)
    def f(self, nums, target):
        dp = [0] * (target + 1)
        dp[0] = 1
        for i in nums:
            temp = dp.copy()
            for j in range(target - i + 1):
                if dp[j]:
                    temp[j + i] += dp[j]
            dp = temp
        return dp[-1]
```
## Leetcode
```
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        s = sum(nums)
        if s < S or (s + S) & 1:
            return 0
        else:
            return self.f(nums, (s + S) >> 1)
    def f(self, nums, target):
        dp = [0] * (target + 1)
        dp[0] = 1
        for i in nums:
            for j in range(target, i - 1, -1):
                dp[j] += dp[j - i]
        return dp[-1]
```
