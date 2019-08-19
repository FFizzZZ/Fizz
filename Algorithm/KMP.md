https://blog.csdn.net/gao506440410/article/details/81812163
https://www.cnblogs.com/c-cloud/p/3224788.html#!comments
```
#### Brute Search
def bs(s, p):
    i, j = 0, 0
    while i < len(s) and j < len(p):
        if s[i] == p[j]:
            i += 1
            j += 1
        else:
            i = i - j + 1
            j = 0
    if j == len(p):
        return s[i - j: i]
    else:
        return -1
```

```
#### KMP Algorithm
def kmp(s, p):
    next = [-1] * len(p)
    k, j = -1, 0
    while j < len(p) - 1:
        if k == -1 or p[j] == p[k]:
            k += 1
            j += 1
            if p[j] != p[k]:
                next[j] = k
            else:
                next[j] = next[k]
        else:
            k = next[k]
            
    i, j = 0, 0
    while i < len(s) and j < len(p):
        if j == -1 or s[i] == p[j]:
            i += 1
            j += 1
        else:
            j = next[j]
    if j == len(p):
        return s[i - j: i]
    else:
        return -1
```
###### Another version written by myself
```
def kmp(s, p):
    next = [-1] * len(p)
    k = -1
    for j in range(len(p) - 1):
        while k != -1 and p[k] != p[j]:
            k = next[k]
        k += 1
        if p[k] == p[j + 1]:
            next[j + 1] = next[k]
        else:
            next[j + 1] = k
            
    i, j = 0, 0
    while i < len(s) and j < len(p):
        if j == -1 or s[i] == p[j]:
            i += 1
            j += 1
        else:
            j = next[j]
    if j == len(p):
        return s[i - j: i]
    else:
        return -1
```
