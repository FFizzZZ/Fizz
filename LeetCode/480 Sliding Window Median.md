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

```
from heapq import heappush, heappop, heapify
class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        to_be_deleted, res = collections.defaultdict(int), []
        top_half, bottom_half = nums[:k], []
        heapify(top_half)
        while len(top_half) - len(bottom_half) > 1:
            heappush(bottom_half, -heappop(top_half))
            
        for i in range(k, len(nums)):
            median = top_half[0] if k % 2 else (top_half[0] - bottom_half[0]) / 2
            res.append(median)
            balance = 0
            curr_num, num_to_be_deleted = nums[i], nums[i - k]
            if num_to_be_deleted >= top_half[0]:
                balance -= 1
                if num_to_be_deleted == top_half[0]:
                    heappop(top_half)
                else:
                    to_be_deleted[num_to_be_deleted] += 1
            else:
                balance += 1
                if num_to_be_deleted == -bottom_half[0]:
                    heappop(bottom_half)
                else:
                    to_be_deleted[num_to_be_deleted] += 1

            if top_half and curr_num >= top_half[0]:
                balance += 1
                heappush(top_half, curr_num)
            else:
                balance -= 1
                heappush(bottom_half, -curr_num)

            if balance > 0:
                heappush(bottom_half, -heappop(top_half))
            elif balance < 0:
                heappush(top_half, -heappop(bottom_half))

            while top_half and to_be_deleted[top_half[0]]:
                to_be_deleted[top_half[0]] -= 1
                heappop(top_half)
            while bottom_half and to_be_deleted[-bottom_half[0]]:
                to_be_deleted[-bottom_half[0]] -= 1
                heappop(bottom_half)
        median = top_half[0] if k % 2 else (top_half[0] - bottom_half[0]) / 2
        res.append(median)
        return res
```
