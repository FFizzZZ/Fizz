## Leetcode
```
class Solution:
    def increasingTriplet(self, nums):
        first, second = float('inf'), float('inf')
        for x in nums:
            if x <= first:
                first = x
            elif x <= second:
                second = x
            else:
                return True
        return False
```
