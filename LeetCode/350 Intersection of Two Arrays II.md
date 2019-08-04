## Leetcode
```
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d = collections.defaultdict(int)
        for x in nums1:
            d[x] += 1
        ans = []
        for x in nums2:
            if x in d and d[x] > 0:
                ans.append(x)
                d[x] -= 1
        return ans
```

```
class Solution:
    def intersect(self, nums1, nums2):
        a, b = map(collections.Counter, (nums1, nums2))
        return list((a & b).elements())
```
