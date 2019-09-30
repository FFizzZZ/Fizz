## Leetcode
```
class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        def dfs(pos, prev_num, curr_val, expr):
            if pos == L:
                if curr_val == target:
                    ans.append(expr)
                return
            
            if max(1, abs(prev_num)) * (int(num[pos:])) < abs(target - curr_val):
                return

            for i in range(pos+1, L+1):
                digits = num[pos:i]
                if len(digits) == 1 or digits[0] != '0':
                    n = int(digits)
                    dfs(i, n, curr_val + n, expr + '+' + digits)
                    dfs(i, -n, curr_val - n, expr + '-' + digits)
                    dfs(i, prev_num * n, curr_val - prev_num + prev_num * n, expr + '*' + digits)
        L = len(num)
        ans = []
        for i in range(1, L+1):
            digits = num[:i]
            if len(digits) == 1 or digits[0] != '0':
                dfs(i, int(digits), int(digits), digits)
        return ans
```
