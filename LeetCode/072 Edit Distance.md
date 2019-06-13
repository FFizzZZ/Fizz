## dynamic programming: two vector
```
class Solution:
    def minDistance(self, word1, word2):
        m = len(word1)
        n = len(word2)
        pre = [0] * (n + 1)
        cur = [0] * (n + 1)
        for i in range(1, n + 1):
            pre[i] = i
        for i in range(1, m + 1):
            cur[0] = i
            for j in range(1, n + 1):
                if word1[i-1] == word2[j-1]:
                    cur[j] = pre[j-1]
                else:
                    cur[j] = 1 + min(cur[j-1], pre[j], pre[j-1])
            pre = cur[:]        # pay attention to [:] !!!!
        return pre[-1]
```
## one vector
```
class Solution:
    def minDistance(self, word1, word2):
        m = len(word1)
        n = len(word2)
        cur = [0] * (n + 1)
        for i in range(1, n + 1):
            cur[i] = i
        for i in range(1, m + 1):
            pre = cur[0]
            cur[0] = i
            for j in range(1, n + 1):
                temp = cur[j]
                if word1[i-1] == word2[j-1]:
                    cur[j] = pre
                else:
                    cur[j] = 1 + min(cur[j-1], cur[j], pre)
                pre = temp
        return cur[-1]
```
