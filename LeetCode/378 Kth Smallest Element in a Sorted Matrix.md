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
###### Interesting
```
class Solution(object):
    def kthSmallest(self, matrix, k):
        n = len(matrix)
        l, r = matrix[0][0], matrix[-1][-1]
        while l < r:
            mid = (l + r) // 2
            if self.f(matrix, n, mid) < k:
                l = mid + 1
            else:
                r = mid
        return l      
    def f(self, matrix, n, val):
        x, y = n - 1, 0
        cnt = 0
        while x >= 0 and y < n:
            if matrix[x][y] <= val:
                cnt += x + 1
                y += 1
            else:
                x -= 1
        return cnt
```






