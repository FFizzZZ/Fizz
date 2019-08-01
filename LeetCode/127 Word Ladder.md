## Leetcode
```
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        if endWord not in wordList: return 0
        n = len(beginWord)
        d = collections.defaultdict(list)
        for word in wordList:
            for i in range(n):
                d[word[:i] + '*' + word[i+1:]].append(word)
        queue = collections.deque([(beginWord, 1)])
        visited = set()
        while queue:
            cur, level = queue.popleft()
            for i in range(n):
                tmp = cur[:i] + '*' + cur[i+1:]
                for word in d[tmp]:
                    if word == endWord:
                        return level + 1
                    if word not in visited:
                        queue.append((word, level + 1))
                        visited.add(word)
        return 0
```
