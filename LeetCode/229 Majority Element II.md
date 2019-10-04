## Leetcode
```
class Solution:
    def majorityElement(self, nums):
        if not nums: return []
        cnt1 = 0; n1 = None
        cnt2 = 0; n2 = None
        for x in nums:
            if x == n1:
                cnt1 += 1
            elif x == n2:
                cnt2 += 1
            elif cnt1 == 0:
                n1 = x; cnt1 = 1
            elif cnt2 == 0:
                n2 = x; cnt2 = 1
            else:
                cnt1 -= 1
                cnt2 -= 1
        return [x for x in [n1, n2] if nums.count(x) > len(nums) // 3]
```

```
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        d = collections.Counter(nums)
        return [key for key, val in enumerate(d) if val > len(nums) // 3]
```
