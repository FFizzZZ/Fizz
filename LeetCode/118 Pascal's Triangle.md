```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0: return []
        ans = [[1]]
        for _ in range(numRows - 1):
            nums = ans[-1]
            temp = [1]
            for i in range(len(nums) - 1):
                temp.append(nums[i] + nums[i + 1])
            temp.append(1)
            ans.append(temp)
        return ans
```

## Leetcode
```
class Solution:
    def generate(self, num_rows):
        triangle = []
        for row_num in range(num_rows):
            row = [None for _ in range(row_num+1)]
            row[0], row[-1] = 1, 1
            for j in range(1, len(row)-1):
                row[j] = triangle[row_num-1][j-1] + triangle[row_num-1][j]
            triangle.append(row)
        return triangle
```
