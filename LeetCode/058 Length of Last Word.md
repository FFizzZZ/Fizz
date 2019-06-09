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
