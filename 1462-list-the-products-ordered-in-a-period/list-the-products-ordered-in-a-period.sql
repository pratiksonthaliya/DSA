# Write your MySQL query statement below

SELECT p.product_name, t.units AS unit
FROM

((SELECT DISTINCT o.product_id, o.order_date, SUM(CASE WHEN DATE_FORMAT(o.order_date, '%Y-%m') = '2020-02' THEN unit ELSE 0 END) AS units
FROM Orders o
GROUP BY o.product_id
HAVING units >= 100
) AS t

LEFT JOIN Products p
ON t.product_id = p.product_id);