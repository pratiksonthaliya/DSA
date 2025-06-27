# Write your MySQL query statement below

SELECT x, y, z, (
        IF(x + y <= z OR y + z <= x OR z + x <= y, "No", "Yes")
        --     THEN "No"
        -- ELSE
        --     THEN "Yes"
        -- END
) triangle
FROM Triangle;