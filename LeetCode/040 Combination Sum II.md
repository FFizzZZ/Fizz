```
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        candidates.sort()
        self.f(candidates, target, 0, [], ans)
        return ans
    def f(self, candidates, target, start, path, ans):
        if target == 0:
            ans.append(path[:])
        else:
            for i in range(start, len(candidates)):
                if target < candidates[i]:
                    break
                elif i > start and candidates[i] == candidates[i - 1]:
                    continue
                else:
                    path.append(candidates[i])
                    self.f(candidates, target - candidates[i], i + 1, path, ans)
                    path.pop()
```
