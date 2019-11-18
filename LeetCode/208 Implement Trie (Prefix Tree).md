## Leetcode
```
class Trie:
    def __init__(self):
        self.root = {}

    def insert(self, word: str) -> None:
        cur = self.root
        for char in word:
            if char not in cur:
                cur[char] = dict()
            cur = cur[char]
        cur['#'] = True

    def search(self, word: str) -> bool:
        cur = self.find(word)
        if cur and '#' in cur:
            return True
        return False
        

    def startsWith(self, prefix: str) -> bool:
        return True if self.find(prefix) else False
        
    def find(self, prefix: str):
        cur = self.root
        for char in prefix:
            if char not in cur:
                return
            cur = cur[char]
        return cur
```
------------------------------------------------------------------------------------
```
class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word: str) -> None:
        current = self.root
        for letter in word:
            current = current.children[letter]
        current.is_word = True

    def search(self, word: str) -> bool:
        current = self.root
        for letter in word:
            current = current.children.get(letter)
            if current is None:
                return False
        return current.is_word
        
    def startsWith(self, prefix: str) -> bool:
        current = self.root
        for letter in prefix:
            current = current.children.get(letter)
            if current is None:
                return False
        return True
```



```
class TrieNode:
    def __init__(self):
        self.word=False
        self.children={}
    
class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node=self.root
        for i in word:
            if i not in node.children:
                node.children[i]=TrieNode()
            node=node.children[i]
        node.word=True

    def search(self, word):
        node=self.root
        for i in word:
            if i not in node.children:
                return False
            node=node.children[i]
        return node.word

    def startsWith(self, prefix):
        node=self.root
        for i in prefix:
            if i not in node.children:
                return False
            node=node.children[i]
        return True
```
 
