## Leetcode
```
class Solution:
    def fractionToDecimal(self, numerator, denominator):
        sign = '-' if numerator * denominator < 0 else ''
        n, r = divmod(abs(numerator), abs(denominator))
        ans = [sign + str(n) + '.']
        index = 0
        d = {}
        while r not in d:
            d[r] = index
            index += 1
            n, r = divmod(r * 10, abs(denominator))
            ans.append(str(n))
        ind = d[r]
        ans.insert(ind + 1, '(')
        ans.append(')')
        return ''.join(ans).replace('(0)', '').rstrip('.')
```

