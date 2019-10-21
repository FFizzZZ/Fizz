```
delete p1 from Person as p1, Person as p2
where p1.Email = p2.Email and p1.Id > p2.Id;
```

```
delete from
    Person
where
    id not in (select * from (select min(Id) from Person group by Email) as tmp);
```
