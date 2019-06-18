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
```class Solution:
    def longestPalindrome(self, s: str) -> str:
        t = '#'.join('$' + s + '^')
        n = len(t)
        p = [0] * n
        c, r = -1, -1
        for i in range(1, n - 1):
            p[i] = c + r + 1 > i and min(c + r - i, p[2 * c - i])
            while t[i + 1 + p[i]] == t[i - 1 - p[i]]:
                p[i] += 1
            if i + 1 + p[i] > c + 1 + r:
                c, r = i, p[i]
        r = max(p)
        c = p.index(r)
        return s[(c - r) // 2 : (c + r) // 2]
```
```
class Solution:
    #Manacher algorithm
    #http://en.wikipedia.org/wiki/Longest_palindromic_substring
    
    def longestPalindrome(self, s):
        # Transform S into T.
        # For example, S = "abba", T = "^#a#b#b#a#$".
        # ^ and $ signs are sentinels appended to each end to avoid bounds checking
        T = '#'.join('^{}$'.format(s))
        n = len(T)
        P = [0] * n
        C = R = 0
        for i in range (1, n-1):
            P[i] = (R > i) and min(R - i, P[2*C - i]) # equals to i' = C - (i-C)
            # Attempt to expand palindrome centered at i
            while T[i + 1 + P[i]] == T[i - 1 - P[i]]:
                P[i] += 1
    
            # If palindrome centered at i expand past R,
            # adjust center based on expanded palindrome.
            if i + P[i] > R:
                C, R = i, i + P[i]
    
        # Find the maximum element in P.
        maxLen, centerIndex = max((n, i) for i, n in enumerate(P))
        return s[(centerIndex  - maxLen)//2: (centerIndex  + maxLen)//2]
```
