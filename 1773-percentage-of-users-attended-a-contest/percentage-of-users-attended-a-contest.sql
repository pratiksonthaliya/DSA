# Write your MySQL query statement below
-- SELECT COUNT(*) FROM Users;

WITH total_user as (SELECT COUNT(user_id) as cnt FROM Users)

SELECT contest_id, ROUND(COUNT(user_id) * 100 / (t.cnt), 2) AS percentage
FROM Register, total_user t
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;