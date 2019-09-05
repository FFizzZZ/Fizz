## Leetcode
```
class Solution:
    def numMatchingSubseq(self, S: str, words: List[str]) -> int:
        cnt = 0
        positive = set()
        negative = set()
        for word in words:
            if word not in positive and word not in negative:
                if self.check(word, S):
                    positive.add(word)
                    cnt += 1
                else:
                    negative.add(word)
            elif word in positive:
                cnt += 1
        return cnt
    
    def check(self, word, S):
        index = 0
        for c in word:
            index = S.find(c, index) + 1
            if not index:
                return False
        return True
```
