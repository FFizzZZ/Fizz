## Leetcode
#### Dynamic Programming
```
class Solution:
    def lenLongestFibSubseq(self, A: List[int]) -> int:
        d = {x: i for i, x in enumerate(A)}
        dp = collections.defaultdict(lambda: 2)
        ans = 0
        for k, z in enumerate(A):
            for j in range(k):
                i = d.get(z - A[j], None)
                if i is not None and i < j:
                    tmp = dp[j, k] = dp[i, j] + 1
                    if tmp > ans: ans = tmp
        return ans if ans > 2 else 0
```
#### FASTEST
###### I think this method could be even faster since the if clause is not precise enough.
```
class Solution:
    def lenLongestFibSubseq(self, nums: List[int]) -> int:
        ans = 0
        s = set(nums)
        for i in range(len(nums) - 2):
            for j in range(i + 1, len(nums)):
                a, b = nums[i], nums[j]
                streak = 0
                if b * (ans - 2) >= nums[-1]:
                    break
                while a + b in s:
                    if not streak:
                        streak = 3
                    else:
                        streak += 1
                    a, b = b, a + b
                if streak > ans:
                    ans = streak
        return ans
```
