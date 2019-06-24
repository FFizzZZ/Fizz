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
        
```
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []
        self.f(s, 0, [], ans)
        return ans
    def f(self, s, index, path, ans):
        l = len(path)
        if l > 4: return
        if l == 4 and index == len(s): ans.append('.'.join(path))
        for i in range(1, 4):
            if index + i > len(s): break
            temp = s[index:index+i]
            if temp[0] == '0' and len(temp) > 1 or i == 3 and int(temp) > 255:
                continue
            path.append(temp)
            self.f(s, index + i, path, ans)
            path.pop()
```
        
        
        
        
        


     
        
        
