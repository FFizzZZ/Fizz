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
