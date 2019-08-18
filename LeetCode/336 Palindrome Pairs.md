## Leetcode
```
class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        d = {s[::-1]:i for i, s in enumerate(words)}
        ans = []
        
        for i, s in enumerate(words):
            if s:
                for j in range(len(s)):
                    left, right = s[:j], s[j:]
                    
                    if left in d and right == right[::-1]:
                        ans.append([i, d[left]])
                        
                    if right in d and d[right] != i and left == left[::-1]:
                        ans.append([d[right], i])
            else:
                for index, word in enumerate(words):
                    if index != i and word[::-1] == word:
                        ans.append([i, index])
                        
        return ans
```
