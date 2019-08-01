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
from collections import defaultdict
class Solution(object):
    def __init__(self):
        self.length = 0
        self.all_combo_dict = defaultdict(list)
    def visitWordNode(self, queue, visited, others_visited):
        current_word, level = queue.popleft()
        for i in range(self.length):
            intermediate_word = current_word[:i] + "*" + current_word[i+1:]
            for word in self.all_combo_dict[intermediate_word]:
                if word in others_visited:
                    return level + others_visited[word]
                if word not in visited:
                    visited[word] = level + 1
                    queue.append((word, level + 1))
        return None

    def ladderLength(self, beginWord, endWord, wordList):
        if endWord not in wordList:
            return 0
        self.length = len(beginWord)

        for word in wordList:
            for i in range(self.length):
                self.all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)
        queue_begin = collections.deque([(beginWord, 1)]) 
        queue_end = collections.deque([(endWord, 1)]) 
        visited_begin = {beginWord: 1}
        visited_end = {endWord: 1}
        ans = None

        while queue_begin and queue_end:
            ans = self.visitWordNode(queue_begin, visited_begin, visited_end)
            if ans:
                return ans
            ans = self.visitWordNode(queue_end, visited_end, visited_begin)
            if ans:
                return ans
        return 0
```
