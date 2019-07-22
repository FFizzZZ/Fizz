## Leetcode
```
class Solution:
    def fractionToDecimal(self, numerator, denominator):
        n, remainder = divmod(abs(numerator), abs(denominator))
        sign = '-' if numerator*denominator < 0 else ''
        result = [sign+str(n), '.']
        index = 0
        d = {}
        while remainder not in d:
            d[remainder] = index
            index += 1
            n, remainder = divmod(remainder*10, abs(denominator))
            result.append(str(n))
        idx = d[remainder]
        result.insert(idx+2, '(')
        result.append(')')
        return ''.join(result).replace('(0)', '').rstrip('.')
```

