```
select FirstName, LastName, city, State
from Person
left join Address
on Person.PersonId = Address.PersonId;
```
