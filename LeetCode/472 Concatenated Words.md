## Leetcode
```
class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        words_set = set(words)
        
        def helper(word, start):
            if word[start:] in words_set:
                return True
            for j in range(start+1, len(word)):
                if word[start:j] in words_set and helper(word, j):
                    return True
            return False
        
        results = []
        for word in words:
            for i in range(1, len(word)):
                if word[:i] in words_set and helper(word, i):
                    results.append(word)
                    break
        return results
```
