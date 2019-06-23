## From right to left, best
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
## move elements of nums1 to the right side
```
class Solution:
    def merge(self, nums1, m, nums2, n):
        for i in range(m - 1, -1, -1):    ## from the last to the first!
            nums1[i + n] = nums1[i]
        i, j = n, 0
        k = 0
        while j < n:
            if i == m + n:
                nums1[k:] = nums2[j:]
                break
            if nums1[i] < nums2[j]:
                nums1[k] = nums1[i]
                i += 1
                k += 1
            else:
                nums1[k] = nums2[j]
                j += 1
                k += 1
```

