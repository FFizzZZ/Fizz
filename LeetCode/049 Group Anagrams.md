## Sort
```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:        
        ans = collections.defaultdict(list)
        for s in strs:
            ans[tuple(sorted(s))].append(s)
        return ans.values()
```

## Count
```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:        
        ans = collections.defaultdict(list)
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - 97] += 1
            ans[tuple(count)].append(s)
        return ans.values()
```
        

## Prime
```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:        
        prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103]
        d = collections.defaultdict(list)
        for s in strs:
            key = 1
            for ch in s:
                key *= prime[ord(ch) - 97]
            d[key].append(s)
        return d.values()
```
算术基本定理，又称为正整数的唯一分解定理，即：每个大于1的自然数，要么本身就是质数，要么可以写为2个以上的质数的积，而且这些质因子按大小排列之后，写法仅有一种方式。
利用这个，我们把每个字符串都映射到一个正数上。
用一个数组存储质数 prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103}。
然后每个字符串的字符减去 ' a ' ，然后取到 prime 中对应的质数。把它们累乘。
例如 abc ，就对应 'a' - 'a'， 'b' - 'a'， 'c' - 'a'，即 0, 1, 2，也就是对应素数 2 3 5，然后相乘 2 3 5 = 30，就把 "abc" 映射到了 30。
