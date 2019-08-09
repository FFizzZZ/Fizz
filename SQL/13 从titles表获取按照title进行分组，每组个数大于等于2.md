```
SELECT title, COUNT(*) AS t
FROM titles
GROUP BY title
HAVING t >= 2
```
