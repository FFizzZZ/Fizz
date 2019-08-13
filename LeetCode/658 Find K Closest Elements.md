## Leetcode
#### Sorting
```
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        arr.sort(key = lambda y: abs(x - y))
        ans = sorted(arr[:k])
        return ans
```

#### Binary Search
```
class Solution:
    def findClosestElements(self, A, k, x):
        left, right = 0, len(A) - k
        while left < right:
            mid = (left + right) // 2
            if x - A[mid] > A[mid + k] - x:  # pay attention here!!!
                left = mid + 1               # because the question prefer a smaller element.
            else:
                right = mid
        return A[left:left + k]
```

```
class Solution(object):
    def findClosestElements(self, arr, k, x):
        n = len(arr)
        end = max(bisect.bisect_right(arr, x), k)
        while end < n and arr[end]-x < x - arr[end - k]:
            end += 1
        return arr[end-k:end]
```
