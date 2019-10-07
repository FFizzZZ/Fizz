## Leetcode
```
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        w = []
        sum_ = 0
        for idx, val in enumerate(nums):
            sum_ += val
            if idx >= k: sum_ -= nums[idx - k]
            if idx >= k - 1: w.append(sum_)
        
        left = [0] * len(w)
        idx = 0
        for i in range(len(w)):
            if w[i] > w[idx]:
                idx = i
            left[i] = idx
            
        right = [0] * len(w)
        idx = len(w) - 1
        for i in range(len(w) - 1, -1, -1):
            if w[i] >= w[idx]:
                idx = i
            right[i] = idx
        
        ans = None
        for m in range(k, len(w) - k):
            l, r = left[m - k], right[m + k]
            if ans is None or (w[m] + w[l] + w[r] > w[ans[0]] + w[ans[1]] + w[ans[2]]):
                ans = l, m, r
        return ans
```
