```
SELECT e.emp_no, d.emp_no AS manager_no
FROM dept_emp AS e
LEFT JOIN dept_manager AS d
ON e.dept_no = d.dept_no
WHERE e.to_date = '9999-01-01' AND d.to_date = '9999-01-01' AND e.emp_no != d.emp_no
```
