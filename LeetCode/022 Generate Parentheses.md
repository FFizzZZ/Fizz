```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        self.generate(n, n, '', ans)
        return ans
    def generate(self, l, r, path, ans):
        if l == r == 0:
            ans.append(path)
            return
        if l > 0:
            self.generate(l - 1, r, path + '(', ans)
        if l < r:
            self.generate(l, r - 1, path + ')', ans)
```


## Leetcode
 #### Closure Number
 ```
 class Solution(object):
    def generateParenthesis(self, N):
        if N == 0: return ['']
        ans = []
        for c in xrange(N):
            for left in self.generateParenthesis(c):
                for right in self.generateParenthesis(N-1-c):
                    ans.append('({}){}'.format(left, right))
        return ans
```
