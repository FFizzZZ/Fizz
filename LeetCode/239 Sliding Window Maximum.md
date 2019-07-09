## Leecode
```
class Solution:
    def maxSlidingWindow(self, nums, k):
        d = collections.deque()
        out = []
        for i, n in enumerate(nums):
            while d and nums[d[-1]] < n:
                d.pop()
            d += i,
            if d[0] == i - k:
                d.popleft()
            if i >= k - 1:
                out += nums[d[0]],
        return out
```

```
class Solution:
    def maxSlidingWindow(self, nums, k):
        if not nums: return []
        n = len(nums)
        max_left = [0] * n
        max_right = [0] * n
        max_left[0] = nums[0]
        max_right[-1] = nums[-1]
        for i in range(1, n):
            max_left[i] = nums[i] if i % k == 0 else max(max_left[i - 1], nums[i])
            j = n - i - 1
            max_right[j] = nums[j] if j % k == 0 else max(max_right[j + 1], nums[j])
        ans = []
        for i in range(n - k + 1):
            ans.append(max(max_right[i], max_left[i + k - 1]))
        return ans
```
