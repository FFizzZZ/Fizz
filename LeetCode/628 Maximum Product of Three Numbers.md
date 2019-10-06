```
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums.sort()
        a = nums[-1] * nums[-2] * nums[-3]
        b = nums[0] * nums[1] * nums[-1]
        return max(a, b)
```

## Leetcode
```
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        max1 = max2 = max3 = float("-inf")
        min1 = min2 = float("inf")
        for x in nums:
            if x < min1:
                min2 = min1
                min1 = x
            elif x < min2:
                min2 = x
                
            if x > max1:
                max3 = max2
                max2 = max1
                max1 = x
            elif x > max2:
                max3 = max2
                max2 = x
            elif x > max3:
                max3 = x
        
        return max(min1 * min2 * max1, max1 * max2 * max3)
```
