```
select
    (case
        when mod(id, 2) != 0 and total != id then id + 1
        when mod(id, 2) != 0 and total = id then id
        else id - 1
     end) as id,
     student
from
    seat,
    (select count(*) as total from seat) as tmp
order by
    id asc;
```

```
SELECT
    s1.id, COALESCE(s2.student, s1.student) AS student
FROM
    seat s1
        LEFT JOIN
    seat s2 
ON 
    ((s1.id + 1) ^ 1) - 1 = s2.id
ORDER BY 
    s1.id;
```
