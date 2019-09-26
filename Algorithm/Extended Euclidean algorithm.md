* https://zh.wikipedia.org/wiki/%E6%89%A9%E5%B1%95%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97%E7%AE%97%E6%B3%95
* 3升5升杯子求4升水 https://blog.csdn.net/lanchunhui/article/details/50594649
* 扩展欧几里得算法及应用 https://blog.csdn.net/lanchunhui/article/details/50593075
```
def ext_euclid(a, b):
     if b == 0:
         return 1, 0, a
     else:
         x, y, q = ext_euclid(b, a % b) # q = gcd(a, b) = gcd(b, a%b)
         x, y = y, (x - (a // b) * y)
         return x, y, q
```
