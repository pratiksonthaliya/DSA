# Write your MySQL query statement below

with temp as (
    select email,
    COUNT(email) as cnt
    from person
    GROUP BY email
)

select distinct email from temp where cnt > 1;