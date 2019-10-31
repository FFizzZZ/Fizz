```
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        m = collections.Counter(magazine)
        r = collections.Counter(ransomNote)
        for key in r:
            if key not in m or r[key] > m[key]:
                return False
        return True
```

## Leetcode
```
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for i in range(len(ransomNote)):
            if ransomNote[i] not in magazine:
                return False
            magazine = magazine.replace(ransomNote[i], '', 1)
        return True
```

```
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for letter in set(ransomNote):
            if ransomNote.count(letter) > magazine.count(letter):
                return False
        return True
```
