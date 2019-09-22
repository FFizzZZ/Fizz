## Leetcode
```
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList):
        if endWord not in wordList: return []
        forward, backward = {beginWord}, {endWord}
        wordList = set(wordList)
        d = collections.defaultdict(list)
        direction = 1
        letters = string.ascii_lowercase
        length = len(endWord)
        while forward:
            if len(forward) > len(backward):
                forward, backward = backward, forward
                direction *= -1
            cur = set()
            wordList -= forward
            for word in forward:
                for i in range(length):
                    x, y = word[:i], word[i + 1:]
                    for letter in letters:
                        tmp = x + letter + y
                        if tmp in wordList:
                            cur.add(tmp)
                            if direction == 1: 
                                d[tmp].append(word)
                            else:
                                d[word].append(tmp)
            if cur & backward:
                ans = [[endWord]]
                while ans[0][0] != beginWord:
                    ans = [[x] + y for y in ans for x in d[y[0]]]
                return ans
            forward = cur
        return []
```
