## Leetcode
```
class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        def dfs(idx, pre, cur, path):
            if idx == l:
                if cur == target: ans.append(path)
                return
            if max(1, abs(pre)) * (int(num[idx:])) < abs(target - cur): return
            
            for i in range(idx + 1, l + 1):
                digits = num[idx:i]
                if len(digits) == 1 or digits[0] != "0":
                    n = int(digits)
                    dfs(i, n, cur + n, path + "+" + digits)
                    dfs(i, -n, cur - n, path + "-" + digits)
                    dfs(i, pre * n, cur - pre + n * pre, path + "*" + digits)
        l = len(num)
        ans = []
        for i in range(1, l + 1):
            digits = num[:i]
            if i == 1 or digits[0] != "0":
                dfs(i, int(digits), int(digits), digits)
        return ans
```
