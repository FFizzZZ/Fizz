```
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans = cnt = 0
        for x in nums:
            if x == 1:
                cnt += 1
                if cnt > ans:
                    ans = cnt
            else:
                cnt = 0
        return ans
```
