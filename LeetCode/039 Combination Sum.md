```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        candidates.sort()
        self.f(candidates, target, 0, [], ans)
        return ans
    def f(self, candidates, target, start, path, ans):
        if target == 0:
            ans.append(path[:])
        else:
            for i in range(start, len(candidates)):
                if target >= candidates[i]:
                    path.append(candidates[i])
                    self.f(candidates, target - candidates[i], i, path, ans)
                    path.pop()
```
