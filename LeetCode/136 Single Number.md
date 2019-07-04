## Leetcode
### Hash Table
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        d = {}
        for i in nums:
            try:
                d.pop(i)
            except:
                d[i] = 1
        return d.popitem()[0]
```

### Math
2 * (a + b + c) - (a + a + b + b + c) = c
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return 2 * sum(set(nums)) - sum(nums)
```

### Bit Manipulation
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a = 0
        for i in nums:
            a ^= i
        return a
```
