# Write your MySQL query statement below

SELECT 
    p.product_name,
    SUM(o.unit) AS unit
FROM Orders AS o
LEFT JOIN Products AS p
    ON o.product_id = p.product_id
WHERE DATE_FORMAT(o.order_date, '%Y-%m') = '2020-02'
GROUP BY o.product_id
HAVING unit >= 100;