# Write your MySQL query statement below

SELECT machine_id, ROUND(AVG(time), 3) AS processing_time
FROM 
(SELECT machine_id, process_id, ROUND(MAX(timestamp) - MIN(timestamp), 3) AS time
FROM Activity
GROUP BY machine_id, process_id) AS der
GROUP BY machine_id;