```
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for x in num:
            while stack and k and stack[-1] > x:
                k -= 1
                stack.pop()
            stack.append(x)
        ans = ''.join(stack[:len(stack) - k]).lstrip('0')
        return ans if ans else '0'      #  return ''.join(stack[:-k or None]).lstrip('0') or '0'

```
