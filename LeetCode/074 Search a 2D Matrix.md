```
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        r, c = len(matrix) - 1, 0
        while r > -1 and c < len(matrix[0]):
            if matrix[r][c] == target:
                return True
            elif matrix[r][c] > target:
                r -= 1
            else:
                c += 1
        return False
```

## leetcode
```
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix: return False
        r, c = len(matrix), len(matrix[0])
        left, right = 0, r * c - 1
        while left <= right:
            mid = (left + right) // 2
            val = matrix[mid // c][mid % c]
            if val == target:
                return True
            elif val < target:
                left = mid + 1
            else:
                right = mid - 1
        return False
```
