# Write your MySQL query statement below

SELECT name 
FROM Employee
WHERE id IN (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(managerId) > 4 AND COUNT(managerId) IS NOT NULL
);