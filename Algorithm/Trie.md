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


```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct trie {
    char c;
    bool isWord;
    struct trie *children[26];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *node = (Trie *)malloc(sizeof(Trie));
    memset(node, 0, sizeof(*node));

    return node;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Trie *node = obj;

    while (*word) {
        int idx = *word - 'a';

        if (node->children[idx] == NULL) {
            Trie *new = trieCreate();
            new->c = *word;

            node->children[idx] = new;
        }

        node = node->children[idx];
        word++;
    }

    node->isWord = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    Trie *node = obj;

    while (*word) {
        int idx = *word - 'a';

        if (node->children[idx] == NULL)
            return false;

        node = node->children[idx];
        word++;
    }

    return node->isWord;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *node = obj;

    while (*prefix) {
        int idx = *prefix - 'a';

        if (node->children[idx] == NULL)
            return false;

        node = node->children[idx];
        prefix++;
    }

    return true;
}

void trieFree(Trie* obj) {
    Trie *node = obj;
    
    for (int i = 0; i < 26; i++) {
        if (node->children[i] == NULL)
            continue;
        
        trieFree(node->children[i]);
    }

    free(node);
}
```
