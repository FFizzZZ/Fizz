## Leetcode
```
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key = lambda x: [x[0], -x[1]])
        n = len(envelopes)
        h = [0] * n
        size = 0
        for i in range(n):
            height = envelopes[i][1]
            l, r = 0, size
            while l < r:
                mid = (l + r) // 2
                if h[mid] < height:
                    l = mid + 1
                else:
                    r = mid
            h[l] = height
            if l == size:
                size += 1
        return size
```
