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

```
class Solution:
    def intersect(self, nums1, nums2):
        nums1.sort()
        nums2.sort()
        ans = []
        p, q = 0, 0
        n1, n2 = len(nums1), len(nums2)
        while p < n1 and q < n2:
            if nums1[p] == nums2[q]:
                ans.append(nums1[p])
                p += 1
                q += 1
            elif nums1[p] < nums2[q]:
                p += 1
            else:
                q += 1
        return ans
```

