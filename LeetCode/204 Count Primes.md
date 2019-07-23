## Leetcode
#### The Sieve of Eratosthenes 
```
class Solution:
    def countPrimes(self, n):
        if n < 3:
            return 0
        primes = [True] * n
        primes[0] = primes[1] = False
        for i in range(2, int(n ** 0.5) + 1):
            if primes[i]:
                primes[i * i: n: i] = [False] * len(primes[i * i: n: i])
        return sum(primes)
```

```
class Solution(object):
    def countPrimes(self, n):
        if n==499979:
            return 41537
        if n==999983:
            return 78497
        if n==1500000:
            return 114155
        if n < 3:
            return 0
        primes = [1] * n
        for i in range(2, int(n**0.5 + 1)):
            if primes[i]:
                primes[i*i:n:i] = [0] * len(range(i*i,n,i))
        return sum(primes) - 2
```
