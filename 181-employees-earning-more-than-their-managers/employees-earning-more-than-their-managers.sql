# Write your MySQL query statement below

SELECT e.name AS "Employee"
FROM Employee m
JOIN Employee e
ON m.id = e.managerId AND m.salary < e.salary;