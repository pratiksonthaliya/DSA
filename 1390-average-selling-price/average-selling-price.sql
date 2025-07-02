SELECT 
    p.product_id,
    IFNULL(
        ROUND(
            SUM(
                CASE 
                    WHEN s.purchase_date BETWEEN p.start_date AND p.end_date THEN s.units * p.price
                    ELSE 0
                END
            ) / NULLIF(
                SUM(
                    CASE
                        WHEN s.purchase_date BETWEEN p.start_date AND p.end_date THEN s.units
                        ELSE 0
                    END
                ), 0
            ),
            2
        ), 
    0) AS average_price
FROM Prices p
LEFT JOIN UnitsSold s
    ON p.product_id = s.product_id
GROUP BY p.product_id;
