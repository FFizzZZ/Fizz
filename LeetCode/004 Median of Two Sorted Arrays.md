```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1, n2 = len(nums1), len(nums2)
        i, j = 0, 0
        cnt = 0
        n = n1 + n2
        l = n // 2
        while cnt < l:
            if i == n1:
                j += 1
                cnt += 1
                continue
            if j == n2:
                i += 1
                cnt += 1
                continue
            if nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
            cnt += 1            
        if n % 2:
            if i == n1: return nums2[j]
            if j == n2: return nums1[i]
            return min(nums1[i], nums2[j])
        else:
            a = max(nums1[i - 1:i] + nums2[j - 1:j])
            b = min(nums1[i:i + 1] + nums2[j:j + 1])
            return (a + b) / 2
```

## Leetcode
```
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m, n = len(nums1), len(nums2)
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m
        imin, imax, half_len = 0, m, (m + n + 1) // 2
        while imin <= imax:
            i = (imin + imax) // 2
            j = half_len - i
            if i < m and nums2[j - 1] > nums1[i]:
                imin = i + 1
            elif i > 0 and nums1[i - 1] > nums2[j]:
                imax = i - 1
            else:
                if i == 0: max_of_left = nums2[j - 1]
                elif j == 0: max_of_left = nums1[i - 1]
                else: max_of_left = max(nums1[i - 1], nums2[j - 1])
                if (m + n) & 1: return max_of_left

                if i == m: min_of_right = nums2[j]
                elif j == n: min_of_right = nums1[i]
                else: min_of_right = min(nums1[i], nums2[j])
                
                return (max_of_left + min_of_right) / 2
```
