## Leetcode
#### Left and Right Index
```
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        left, right, count = dict(), dict(), collections.defaultdict(int)
        for idx, val in enumerate(nums):
            if val not in left:
                left[val] = idx
            right[val] = idx
            count[val] += 1
        ans = len(nums)
        degree = max(count.values())
        for key in count:
            if count[key] == degree:
                ans = min(ans, right[key] - left[key] + 1)
        return ans
```
