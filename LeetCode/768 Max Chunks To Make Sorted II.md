## Leetcode
#### Sliding Window
```
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        d = collections.defaultdict(int)
        cnt = ans = 0
        for x, y in zip(arr, sorted(arr)):
            d[x] += 1
            val = d[x]
            if val == 1: cnt += 1
            elif val == 0: cnt -= 1
            d[y] -= 1
            val = d[y]
            if val == -1: cnt += 1
            elif val == 0: cnt -= 1
            if cnt == 0: ans += 1
        return ans
```
#### Another method
```
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        arr1 = sorted(arr)
        ans = 0
        m = arr[0]
        cnt = 0
        for index, val in enumerate(arr):
            if val > m:
                m = val
                cnt = 1
            elif val == m:
                cnt += 1
            if m == arr1[index]:
                cnt -= 1
                if cnt == 0:
                    ans += 1
        return ans
```
#### Amazing!
```
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        arr1 = sorted(arr)
        s1, s2 = 0, 0
        ans = 0
        for i in range(len(arr)):
            s1 += arr[i]
            s2 += arr1[i]
            if s1 == s2:
                ans += 1
        return ans
```
