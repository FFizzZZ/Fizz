```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s: return 0
        count = 0
        flag = 0
        for i in s:
            if i == ' ':
                flag = 1
            else:
                if flag:
                    count = 0
                    flag = 0
                count += 1
        return count
```

```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.rstrip(' ').split(' ')[-1])
```

```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if not s: return 0
        for i in range(len(s)-1, -1, -1):
            if s[i] != ' ':
                break
        count = 0
        for j in range(i, -1, -1):
            if s[j] == ' ':
                return count
            count += 1
        return count
```
