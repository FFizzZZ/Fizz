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
