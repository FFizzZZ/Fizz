```
select e.last_name, e.first_name, d.dept_no
from employees as e
inner join dept_emp as d
on d.emp_no = e.emp_no
```

```
select e.last_name, e.first_name, d.dept_no
from employees as e, dept_emp as d
where e.emp_no = d.emp_no
```
