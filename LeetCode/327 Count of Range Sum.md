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
        first = [0]
        for num in nums:
            first.append(first[-1] + num)
        def sort(lo, hi):
            mid = (lo + hi) // 2
            if mid == lo:
                return 0
            count = sort(lo, mid) + sort(mid, hi)
            i = j = mid
            for left in first[lo:mid]:
                while i < hi and first[i] - left <  lower: i += 1
                while j < hi and first[j] - left <= upper: j += 1
                count += j - i
            first[lo:hi] = sorted(first[lo:hi])
            return count
        return sort(0, len(first))
```
