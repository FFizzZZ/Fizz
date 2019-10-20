```
select d.Name as Department, e.Name as Employee, e.Salary as Salary
from Employee as e
inner join Department as d
on e.DepartmentId = d.Id
where (e.DepartmentId, Salary) in
(select DepartmentId, max(Salary) from Employee group by DepartmentId);
```
