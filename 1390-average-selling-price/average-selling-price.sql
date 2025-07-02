# Write your MySQL query statement below

SELECT 
    p.product_id,
    CASE 
        WHEN SUM(s.units) IS NULL THEN 0
        WHEN SUM(s.units) = 0 THEN 0
        ELSE ROUND(SUM(s.units * p.price) / SUM(s.units), 2)
    END AS average_price
FROM Prices p
LEFT JOIN UnitsSold s
ON p.product_id = s.product_id AND s.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id