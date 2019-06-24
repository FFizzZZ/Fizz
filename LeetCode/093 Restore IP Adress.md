```
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []
        self.f(0, s, [], ans)
        return ans
    def f(self, i, s, path, ans):
        l = len(s)
        if i == l:
            if len(path) == 4:
                ans.append('.'.join(path))
            return
        if len(path) < 4:
            if s[i] == '0':
                path.append('0')
                self.f(i + 1, s, path, ans)
                path.pop()
            else:
                path.append(s[i])
                self.f(i + 1, s, path, ans)
                path.pop()
                if i + 1 < l:
                    path.append(s[i:i+2])
                    self.f(i + 2, s, path, ans)
                    path.pop()
                if i + 2 < l and int(s[i:i+3]) < 256:
                    path.append(s[i:i+3])
                    self.f(i + 3, s, path, ans)
                    path.pop()
```

## leetcode
```
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []
        l = len(s)
        for i in range(1, 4):
            if i < l - 2:
                for j in range(i + 1, i + 4):
                    if j < l - 1:
                        for k in range(j + 1, j + 4):
                            if k < l:
                                temp = s1, s2, s3, s4 = s[:i], s[i:j], s[j:k], s[k:]
                                if all(map(self.check, temp)):
                                    ans.append('.'.join(temp))
        return ans
    def check(self, s):
        l = len(s)
        if l > 3 or l < 1 or s[0] == '0' and l > 1 or int(s) > 255:
            return False
        return True
```
        
        
        
     
        
        
