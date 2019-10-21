```
select
    weather.Id
from
    weather inner join weather as w 
on 
    datediff(weather.RecordDate, w.RecordDate) = 1
        and
    weather.Temperature > w.Temperature;
```
