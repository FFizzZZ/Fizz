```
select
    e.emp_no, max(s.salary) as salary, e.last_name, e.first_name
from
    salaries as s, employees as e
where
    e.emp_no = s.emp_no and s.to_date = "9999-01-01"
        and
    s.salary < (select max(salary) from salaries where to_date = "9999-01-01");
```

```
select
    e.emp_no, s.salary, last_name, first_name
from
    employees as e inner join salaries as s
on
    e.emp_no = s.emp_no and s.to_date = "9999-01-01"
        and
    1 = (select count(distinct salary) from salaries s1 where to_date = "9999-01-01"
               and s1.salary > s.salary);
```

