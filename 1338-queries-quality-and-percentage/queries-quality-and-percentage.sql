# Write your MySQL query statement below

SELECT DISTINCT
    query_name, 
    ROUND(AVG(rating/position), 2) AS quality,
    -- SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END)
    ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(rating) * 100, 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name