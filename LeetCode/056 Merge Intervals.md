Sort
```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans = []
        intervals.sort()
        for i in intervals:
            if not ans: ans.append(i)
            elif ans[-1][0] <= i[0] <= ans[-1][1]:
                ans[-1] = [ans[-1][0], max(ans[-1][1], i[1])]
            else: ans.append(i)
        return ans
```
