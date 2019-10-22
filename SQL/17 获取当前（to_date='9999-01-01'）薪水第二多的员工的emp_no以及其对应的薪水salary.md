```
select
    s.emp_no, s.salary
from
    salaries as s
where
    s.to_date = "9999-01-01"
        and
    1 = (select count(distinct s1.salary) from salaries as s1 where s1.salary > s.salary);
```

```
select
    emp_no, salary
from
    salaries
where
    salary = (select distinct salary from salaries order by salary desc limit 1, 1)
        and
    to_date = "9999-01-01";
```
