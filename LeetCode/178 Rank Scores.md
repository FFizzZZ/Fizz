## Leetcode
```
select Score, 
(select count(*) from (select distinct Score s from Scores) tmp where Score <= s) Rank
from Scores
order by Score desc;
```
