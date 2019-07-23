```
class Trie:  
    def __init__(self):
        self.root = {}
        
    def insert(self, word: str) -> None:
        node = self.root
        for i in word:
            if i not in node:
                node[i] = {}
            node = node[i]
        node['#'] = True
        
    def search(self, word: str) -> bool:
        node = self.find(word)
        if node and '#' in node: return True
        return False
        
    def startsWith(self, prefix: str) -> bool:
        node = self.find(prefix)
        return True if node else False
        
    def find(self, prefix):
        node = self.root
        for i in prefix:
            if i not in node:
                return None
            node = node[i]
        return node
```


```
import bisect
class Trie(object):
    def __init__(self):
        self.words = list()   

    def insert(self, word: str) -> None:
        i = bisect.bisect_left(self.words, word)
        if i == len(self.words): 
            self.words.append(word)
        elif i < len(self.words):
            self.words.insert(i, word)
        
    def search(self, word: str) -> bool:
        i = bisect.bisect_left(self.words, word)
        if i < len(self.words) and self.words[i] == word:
            return True
        return False
        
    def startsWith(self, prefix: str) -> bool:
        i = bisect.bisect_left(self.words, prefix)
        if i < len(self.words) and self.words[i].startswith(prefix): 
            return True
        return False
```
