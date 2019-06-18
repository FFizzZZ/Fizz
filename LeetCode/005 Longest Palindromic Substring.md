## dynamic programming
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        dp = [[0] * l for _ in range(l)]
        ans = 1, 0, 0
        for i in range(l - 1, -1, -1):
            for j in range(i, l):
                if i == j:
                    dp[i][i] = 1
                elif j == i + 1:
                    dp[i][j] = s[i] == s[j]
                else:
                    dp[i][j] = dp[i + 1][j - 1] and s[i] == s[j]
                if dp[i][j] and j - i + 1 > ans[0]:
                    ans = j - i + 1, i, j     
        return s[ans[1]:ans[2]+1]
```
```
class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        ans = ''
        for i in range(l):
            ans = max(self.expand(i, i, s), self.expand(i, i + 1, s), ans, key = len)
        return ans
    def expand(self, l, r, s):
        n = len(s)       # this step saves time!
        while l > -1 and r < n and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l + 1: r]
```


## Manacher’s Algorithm
```
class Solution:
    def longestPalindrome(self, s: 'str') -> 'str':
        if not s: return ''
        
        string = ['#']
        for i in s:
            string.append(i)
            string.append('#')
        n = len(string)
        P = [0] * n
        P[1] = 1
        c, r = 1, 2
        for i in range(2, n):
            i1 = 2 * c - i
            if P[i1] < r - i:
                P[i] = P[i1]
            else:
                length = r - i
                P[i] = length
                u = i + length + 1
                l = i - length - 1
                while u <= n-1 and l >= 0:
                    if string[l] == string[u]:
                        P[i] += 1
                        u += 1
                        l -= 1
                    else: break
                c = i
                r = u - 1
        index = P.index(max(P))
        l = (index - P[index]) // 2
        u = (index + P[index] - 2) // 2
        res = s[l : u + 1]
        return res
```
