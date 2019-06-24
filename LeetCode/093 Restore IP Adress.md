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
