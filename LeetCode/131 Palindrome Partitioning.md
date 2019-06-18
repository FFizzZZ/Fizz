## recurse
```
class Solution(object):
    def partition(self, s):
        ans = []
        for i in range(1, len(s) + 1):
            if s[:i] == s[i-1::-1]:
                for j in self.partition(s[i:]):
                    ans.append([s[:i]] + j)
        return ans if ans else [[]]
```

## recurse with memo
```
class Solution(object):
    def partition(self, s):
        d = {}
        return self.f(s, 0, d)
    def f(self, s, start, d):
        if start in d:
            return d[start]
        ans = []
        for i in range(start + 1, len(s) + 1):             # temp = s[start:i]
            if s[start:i] == s[i-1:start:-1] + s[start]:   # if temp == temp[::-1]
                for j in self.f(s, i, d):
                    ans.append([s[start:i]] + j)
        ans = ans if ans else [[]]
        d[start] = ans
        return ans
```

## dynamic programming (best)
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
