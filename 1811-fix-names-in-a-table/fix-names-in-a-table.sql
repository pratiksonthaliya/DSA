# Write your MySQL query statement below
SELECT user_id, CONCAT(SUBSTRING(UPPER(name), 1, 1), SUBSTRING(LOWER(name), 2)) as name
FROM Users
ORDER BY user_id;