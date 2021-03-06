#### Dynamic Programming
```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1: return n
        dp = [1] * n
        for i in range(1, n):
            ans = 1
            for j in range(i):
                if nums[j] < nums[i]:
                    if dp[j] + 1 > ans: ans = dp[j] + 1
            dp[i] = ans
        return max(dp)
```

## Leetcode
#### Recurse with Memorization TLE!
```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        return self.f(-1, 0, nums, {})
    def f(self, pre, cur, nums, d):
        if cur == len(nums): return 0
        if (pre, cur) in d: return d[(pre, cur)]
        taken = 0
        if pre == -1 or nums[pre] < nums[cur]:
            taken = 1 + self.f(cur, cur + 1, nums, d)
        nottaken = self.f(pre, cur + 1, nums, d)
        tmp = max(taken, nottaken)
        d[(pre, cur)] = tmp
        return tmp
```
#### Binary Search
```
class Solution:
    def lengthOfLIS(self, nums):
        tails = [0] * len(nums)
        size = 0
        for x in nums:
            l, r = 0, size
            while l < r:
                mid = (l + r) // 2
                if tails[mid] < x:
                    l = mid + 1
                else:
                    r = mid
            tails[l] = x
            if l + 1 > size:
                size = l + 1
        return size
```

```
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        tails = []
        size = 0
        for x in nums:
            idx = bisect.bisect_left(tails, x)
            if idx == size:
                size += 1
                tails.append(x)
            else:
                tails[idx] = x
        return size
```
            
            
            
     
