CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M = N-1;
RETURN (
  SELECT DISTINCT SALARY 
  FROM Employee 
  ORDER BY SALARY DESC 
  LIMIT 1 OFFSET M
);
END