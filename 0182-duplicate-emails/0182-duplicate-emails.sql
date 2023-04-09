SELECT email
FROM (
  SELECT email
  FROM Person
  WHERE email IS NOT NULL
) AS t
GROUP BY email
HAVING COUNT(*) > 1
