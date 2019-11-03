## Leetcode

```
class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        win = nums[:k]
        ans = []
        win.sort()
        for idx, val in enumerate(nums[k:], k):
            ans.append((win[k // 2] + win[(k - 1) // 2]) / 2)
            win.pop(bisect.bisect_left(win, nums[idx - k]))
            bisect.insort(win, val)
        ans.append((win[k // 2] + win[(k - 1) // 2]) / 2)
        return ans
```
