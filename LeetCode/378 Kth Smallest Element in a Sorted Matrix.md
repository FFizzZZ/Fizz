## Leetcode

#### An idea similar to 23 merging K sorted linked list
```
import queue
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        q = queue.PriorityQueue()
        for j in range(n):
            q.put([matrix[0][j], 0, j])
        for _ in range(k - 1):
            _, x, y = q.get()
            if x == n - 1: continue
            q.put([matrix[x + 1][y], x + 1, y])
        return q.get()[0]
```

#### Binary Search
```
class Solution(object):
    def kthSmallest(self, matrix, k):
        l, r = matrix[0][0], matrix[-1][-1]
        while l < r:
            mid = (l + r) // 2
            if sum(bisect.bisect_right(row, mid) for row in matrix) < k:
                l = mid + 1
            else:
                r = mid
        return l
```
```
class Solution(object):
    def kthSmallest(self, matrix, k):
        l, r = matrix[0][0], matrix[-1][-1]
        while l < r:
            mid = (l + r) // 2 + 1
            if sum(bisect.bisect_left(row, mid) for row in matrix) >= k:
                r = mid - 1
            else:
                l = mid
        return l
```

##### write the function by myself
```
class Solution(object):
    def kthSmallest(self, matrix, k):
        l, r = matrix[0][0], matrix[-1][-1]
        while l < r:
            mid = (l + r) // 2
            if sum(self.f(row, mid) for row in matrix) < k:
                l = mid + 1
            else:
                r = mid
        return l
    def f(self, nums, val):
        l, r = 0, len(nums)
        while l < r:
            mid = (l + r) // 2
            if nums[mid] <= val:
                l = mid + 1
            else:
                r = mid
        return r
```


#### kkkkkk
```
class Solution(object):
    def kthSmallest(self, matrix, k):
        n = len(matrix)
        L, R = matrix[0][0], matrix[n - 1][n - 1]
        while L < R:
            mid = L + ((R - L) >> 1)
            temp = self.search_lower_than_mid(matrix, n, mid)
            if temp < k:
                L = mid + 1
            else:
                R = mid
        return L
    def search_lower_than_mid(self, matrix, n, x):
        i, j = n - 1, 0
        cnt = 0
        while i >= 0 and j < n:
            if matrix[i][j] <= x:
                j += 1
                cnt += i + 1
            else:
                i -= 1
        return cnt
```






