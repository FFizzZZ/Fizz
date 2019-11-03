## Leecode
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


```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        if n <= 1: return nums
        maxx = max(nums[:k])
        ans = [maxx]
        for i in range(1, n - k + 1):
            if nums[i + k - 1] > maxx:
                maxx = nums[i + k - 1]
            elif nums[i - 1] != maxx:
                pass
            else:
                maxx = max(nums[i: i + k])
            ans.append(maxx)
        return ans
```


```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums: return nums
        ans = [max(nums[:k])]
        for i in range(k, len(nums)):
            pre = ans[-1]
            if nums[i] >= pre:
                ans.append(nums[i])
            elif nums[i - k] < pre:
                ans.append(pre)
            else:
                ans.append(max(nums[i - k + 1: i + 1]))
        return ans
```

#### I think this one is best, but in the leetcode's cases it is not fastest.
```
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        d = collections.deque()
        ans = []
        for idx, val in enumerate(nums):
            while d and nums[d[-1]] < val:
                d.pop()
            d.append(idx)
            if d[0] == idx - k:
                d.popleft()
            if idx >= k - 1:
                ans.append(nums[d[0]])
        return ans
```
