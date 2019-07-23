#### The Sieve of Eratosthenes
This one calculates the number of primes less than n.
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


#### Calculate the number of a specific factor
For example, this one calculates the number of 5 factor in n.
```
class Solution:
    def trailingZeroes(self, n: int) -> int:
        return 0 if n == 0 else n // 5 + self.trailingZeroes(n // 5)
```
