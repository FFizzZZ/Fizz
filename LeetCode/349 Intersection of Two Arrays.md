```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set(nums1)
        s2 = set(nums2)
        ans = []
        if len(s1) > len(s2):
            s1, s2 = s2, s1
        for x in s1:
            if x in s2:
                ans.append(x)
        return ans
```

## Leetcode
```
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        s1 = set(nums1)
        s2 = set(nums2)
        return s1.intersection(s2)
```
