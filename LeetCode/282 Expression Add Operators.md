## Leetcode
```
class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        def dfs(idx, pre, cur, expr):
            if idx == length:
                if cur == target: ans.append(expr)
                return
            if max(1, abs(pre)) * int(num[idx:]) < abs(target - cur): return
            
            for i in range(idx + 1, length + 1):
                digits = num[idx:i]
                if i == idx + 1 or digits[0] != "0":
                    n = int(digits)
                    dfs(i, n, cur + n, expr + "+" + digits)
                    dfs(i, -n, cur - n, expr + "-" + digits)
                    dfs(i, pre * n, cur - pre + pre * n, expr + "*" + digits)
        length = len(num)
        ans = []
        for i in range(1, length + 1):
            digits = num[:i]
            if i == 1 or digits[0] != "0":
                dfs(i, int(digits), int(digits), digits)
        return ans
```
