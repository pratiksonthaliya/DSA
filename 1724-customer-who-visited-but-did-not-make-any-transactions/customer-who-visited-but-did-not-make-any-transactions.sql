# Write your MySQL query statement below

SELECT customer_id, count_no_trans
FROM (
    SELECT customer_id, SUM(CASE WHEN transaction_id IS NULL THEN 1 ELSE 0 END) AS count_no_trans
    FROM Visits v
    LEFT JOIN Transactions t
    ON v.visit_id = t.visit_id
    GROUP BY customer_id
    ORDER BY customer_id
) AS new_t WHERE count_no_trans > 0;