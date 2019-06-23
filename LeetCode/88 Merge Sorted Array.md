## right to left
```
class Solution:
    def merge(self, nums1, m, nums2, n):
        l = m + n - 1
        n, m = n - 1, m - 1
        while n >=0:
            if m >= 0:
                if nums2[n] >= nums1[m]:
                    nums1[l] = nums2[n]
                    n -= 1
                else:
                    nums1[l] = nums1[m]
                    m -= 1
            else:
                nums1[l] = nums2[n]
                n -= 1
            l -= 1
```
