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




```
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        res = ''
        if numerator < 0 and denominator < 0:
            numerator,denominator = abs(numerator), abs(denominator)
        elif numerator < 0 or denominator < 0:
            numerator,denominator = abs(numerator), abs(denominator)
            if numerator != 0:
                res = '-'
        tempres, numerator = divmod(numerator, denominator)
        res += str(tempres)
        if numerator != 0:
            res += '.'
            if numerator < 0:
                numerator = -numerator
                res = '-' + res
        else:
            return res
        numes = {}
        while numerator != 0:
            if numerator not in numes:
                numes[numerator] = len(res)
            else:
                res = res[:numes[numerator]] + '(' + res[numes[numerator]:] + ')'
                return res
            numerator *= 10
            tempres,numerator = divmod(numerator, denominator)
            res += str(tempres)
        return res
```
