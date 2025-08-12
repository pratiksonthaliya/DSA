# Write your MySQL query statement below

SELECT email AS Email FROM (
    SELECT email, COUNT(email) 
    FROM Person
    GROUP BY email
    HAVING COUNT(email) > 1
) t;