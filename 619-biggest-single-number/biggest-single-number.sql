# Write your MySQL query statement below

SELECT MAX(num) AS num
FROM 
    (SELECT num, COUNT(num) AS ct
    FROM MyNumbers
    GROUP BY num) AS t
WHERE t.ct = 1;