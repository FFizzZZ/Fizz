```
class Solution(object):
    def majorityElement(self, nums):
        ans = nums[0]
        count = 0
        for x in nums:
            if ans == x:
                count += 1
            else:
                count -= 1
            if count == 0:
                ans = x
                count = 1
        return ans
```
