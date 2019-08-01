## Leetcode
#### BFS
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

#### Bidirectional Breadth First Search
```
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList = set(wordList)
        if endWord not in wordList: return 0
        n, level = len(beginWord), 1
        d = collections.defaultdict(list)
        for word in wordList:
            for i in range(n):
                d[word[:i] + '*' + word[i + 1:]].append(word)
        head, tail = {beginWord}, {endWord}
        wordList.remove(endWord)
        while head and tail:
            if len(head) > len(tail):
                head, tail = tail, head
            tmp = set()
            for word in head:
                for i in range(n):
                    cur = word[:i] + '*' + word[i + 1:]
                    for x in d[cur]:
                        if x in tail:
                            return level + 1
                        if x in wordList:
                            tmp.add(x)
                            wordList.remove(x)
            head = tmp
            level += 1
        return 0
```

```
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordList = set(wordList)
        if endWord not in wordList: return 0
        n, level = len(beginWord), 1
        head, tail = {beginWord}, {endWord}
        wordList.remove(endWord)
        chars = set('abcdefghijklmnopqrstuvwxyz')
        while head and tail:
            if len(head) > len(tail):
                head, tail = tail, head
            tmp = set()
            for word in head:
                for i in range(n):
                    for c in chars:
                        cur = word[:i] + c + word[i + 1:]
                        if cur in tail:
                            return level + 1
                        if cur in wordList:
                            tmp.add(cur)
                            wordList.remove(cur)
            head = tmp
            level += 1
        return 0
```
