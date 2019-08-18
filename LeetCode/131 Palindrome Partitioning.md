## Leetcode
#### recurse
```
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        if not s: return [[]]
        ans = []
        for i in range(1, len(s) + 1):
            sub = s[:i]
            if sub == sub[::-1]:
                tmp = self.partition(s[i:])
                for y in tmp:
                    ans.append([sub] + y)
        return ans
```

#### recurse with memo
```
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        return self.f(0, s, {})
    def f(self, index, s, d):
        if index == len(s): return [[]]
        if index in d: return d[index]
        ans = []
        for i in range(index + 1, len(s) + 1):
            sub = s[index: i]
            if sub == sub[::-1]:
                for y in self.f(i, s, d):
                    ans.append([sub] + y)
        d[index] = ans
        return ans
```

#### dynamic programming (best)
```
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        def make_results(index,pallindromes, result, results):
            if index >= len(s):
                results += result[:],
            else:
                for pallindrome in pallindromes[index]:
                    make_results(index + len(pallindrome), pallindromes, result + [pallindrome], results)
        
        
        n = len(s)
        is_pallindrome = set()
        pallindromes   = collections.defaultdict(list)
        for i in range(0,len(s)):
            for j in range(i+1):
                if s[i] == s[j] and ((i-j) <= 1 or (j+1,i-1) in is_pallindrome ):
                    is_pallindrome.add( (j,i) )
                    substring = s[j:i+1]
                    pallindromes[j] += substring,
                
        results = []
        make_results(0,pallindromes,[],results)
        return results
```

```
class Solution(object):
    def partition(self, s):
        n = len(s)
        found = set()
        pallindromes = collections.defaultdict(list)
        for i in range(n):
            for j in range(i + 1):
                if s[i] == s[j] and (i - j <= 1 or (j + 1, i - 1) in found):
                    found.add((j, i))
                    pallindromes[j].append(s[j: i + 1])
        
        ans = []
        self.make(0, pallindromes, n, [], ans)
        return ans
    
    def make(self, index, pallindromes, n, path, ans):
        if index == n:
            ans.append(path[:])
            return
        for tmp in pallindromes[index]:
            l = len(tmp)
            path.append(tmp)
            self.make(index + l, pallindromes, n, path, ans)
            path.pop()
```
