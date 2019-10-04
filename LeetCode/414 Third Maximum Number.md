## Leetcode
```
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        m1, m2, m3 = float("-inf"), float("-inf"), float("-inf")
        for x in nums:
            if x > m1:
                m1, m2, m3 = x, m1, m2
            elif m2 < x < m1:
                m2, m3 = x, m2
            elif m3 < x < m2:
                m3 = x
        return m3 if m3 > float('-inf') else m1
```
