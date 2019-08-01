## Leetcode
```
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        ans = []
        self.remove(s, 0, 0, '(', ')', ans)
        return ans
    def remove(self, s, last_i, last_j, left, right, ans):
        count = 0
        for i in range(last_i, len(s)):
            if s[i] == left:
                count += 1
            elif s[i] == right:
                count -= 1
            if count < 0:
                for j in range(last_j, i + 1):
                    if s[j] == right and (j == 0 or s[j - 1] != right):
                        self.remove(s[:j] + s[j + 1:], i, j, left, right, ans)
                return
        if left == '(':
            self.remove(s[::-1], 0, 0, right, left, ans)
        else:
            ans.append(s[::-1])
```
