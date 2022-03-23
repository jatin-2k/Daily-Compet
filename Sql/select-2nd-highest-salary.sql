SELECT (SELECT DISTINCT SALARY
FROM EMPLOYEE
ORDER BY SALARY DESC
LIMIT 1 OFFSET 1) AS SecondHighestSalary;

SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary

SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT MAX(Salary) FROM Employee)