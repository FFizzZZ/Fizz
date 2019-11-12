Input: [[["Python", "Java"], "R"], ["Kobe", "James"]]  
Output: ((Python OR Java) AND R) AND (Kobe OR James)

My Solution:
```
class Solution:
    def f(self, lists):
        stack = []
        flag = 1
        for idx, val in enumerate(lists):
            if isinstance(val, list):
                stack.append("(" +  self.f(val) + ")")
                flag = 0
            else:
                stack.append(val)
        if flag:
            return " OR ".join(stack)
        else:
            return " AND ".join(stack)
```
