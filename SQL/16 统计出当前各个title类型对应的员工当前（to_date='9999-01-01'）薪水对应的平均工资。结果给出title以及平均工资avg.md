```
select
    title, avg(salaries.salary) as avg
from
    salaries left join titles
on
    salaries.emp_no = titles.emp_no
where
    titles.to_date = "9999-01-01" and salaries.to_date = "9999-01-01"
group by
    title;
```
