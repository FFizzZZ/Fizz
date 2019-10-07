## Leetcode
#### Ad-Hoc
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


#### Dynamic Programming
```
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        ans1 = 0
        ans2 = [0, k]
        ans3 = [0, k, 2 * k]
        w1, w2, w3 = sum(nums[:k]), sum(nums[k:2*k]), sum(nums[2*k:3*k])
        max1, max2, max3 = w1, w1 + w2, w1 + w2 + w3
        idx1, idx2, idx3 = 1, k + 1, 2 * k + 1
        while idx3 + k <= len(nums):
            w1 += - nums[idx1 - 1] + nums[idx1 + k - 1]
            w2 += - nums[idx2 - 1] + nums[idx2 + k - 1]
            w3 += - nums[idx3 - 1] + nums[idx3 + k - 1]
            if w1 > max1:
                max1 = w1
                ans1 = idx1
            if max1 + w2 > max2:
                max2 = max1 + w2
                ans2 = [ans1, idx2]
            if max2 + w3 > max3:
                max3 = max2 + w3
                ans3 = ans2 + [idx3]
            idx1 += 1; idx2 += 1; idx3 += 1
        return ans3
```

```
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        for i in range(1, len(nums)):
            nums[i] += nums[i - 1]
        max1 = nums[k - 1]
        max2 = nums[2 * k - 1]
        max3 = nums[3 * k - 1]
        idx1, idx2, idx3 = 0, [0, k], [0, k, 2 * k]
        for i in range(3 * k, len(nums)):
            if max1 < nums[i - 2 * k] - nums[i - 3 * k]:
                max1 = nums[i - 2 * k] - nums[i - 3 * k]
                idx1 = i - 3 * k + 1
            if max2 < nums[i - k] - nums[i - 2 * k] + max1:
                max2 = nums[i - k] - nums[i - 2 * k] + max1
                idx2 = [idx1, i - 2 * k + 1]
            if max3 < nums[i] - nums[i - k] + max2:
                max3 = nums[i] - nums[i - k] + max2
                idx3 = idx2 + [i - k + 1]
        return idx3
```

