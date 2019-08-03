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

#### Generalization
```
class Solution:
    def increasingSubsequence(self, nums, k):
        try:
            inc = [float('inf')] * (k - 1)
            for x in nums:
                inc[bisect.bisect_left(inc, x)] = x
            return k == 0
        except:
            return True
```

```
class Solution:
    def increasingSubsequence(self, nums, k):
        inc = [float('inf')] * (k - 1)
        for x in nums:
            i = bisect.bisect_left(inc, x)
            if i >= k - 1:
                return True
            inc[i] = x
        return k == 0
```
