```
select emp_no from employees
where emp_no not in (select emp_no from dept_manager)
```

```
SELECT employees.emp_no FROM employees LEFT JOIN dept_manager
ON employees.emp_no = dept_manager.emp_no
WHERE dept_no IS NULL
```
