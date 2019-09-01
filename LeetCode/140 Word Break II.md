## Leetcode
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        d = set(wordDict)
        mem = {} 
        def wordBreak(s):
            if s in mem: return mem[s]
            res = []
            if s in d: res.append(s)
            for i in range(1, len(s)):
                right = s[i:]
                if right not in d: continue        
                res += [w + " " + right for w in wordBreak(s[0:i])]
            mem[s] = res
            return mem[s]
        return wordBreak(s)
```


```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        word_set = set(wordDict)
        l_set = set(len(x) for x in word_set)
        return self.f(0, s, word_set, l_set, {})
    
    def f(self, index, s, wordDict, l_set, d):
        if index == len(s): return ['']
        if index in d: return d[index]
        ans = []
        for l in l_set:
            x = s[index:index + l]
            if x in wordDict:
                sub = self.f(index + l, s, wordDict, l_set, d)
                for y in sub:
                    if y == '':
                        ans.append(x)
                    else:
                        ans.append(x + ' ' + y)
        d[index] = ans
        return ans
```
        
        

