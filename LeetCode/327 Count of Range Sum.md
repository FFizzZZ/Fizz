## Leetcode
#### Binary Search FASTEST!
```
class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        total = sum(nums)
        sortedsum = [total]
        cnt = 0
        for x in reversed(nums):
            total -= x
            l = bisect.bisect_left(sortedsum, total + lower)
            r = bisect.bisect_right(sortedsum, total + upper)
            cnt += max(r - l, 0)
            bisect.insort(sortedsum, total)
        return cnt
```
#### Merge Sort
```
class Solution:
    def countRangeSum(self, nums, lower, upper):
        n = len(nums)
        first = [0] * (n + 1)
        for i in range(n):
            first[i + 1] = first[i] + nums[i]
        def mergesort(l, r):
            if r - l <= 1: return 0
            mid = (l + r) // 2
            cnt = mergesort(l, mid) + mergesort(mid, r)
            start = end = mid
            for left in first[l:mid]:
                while start < r and first[start] - left < lower: start += 1
                while end < r and first[end] - left <= upper: end += 1
                cnt += end - start
            first[l:r] = sorted(first[l:r])
            return cnt
        return mergesort(0, len(first))
```
