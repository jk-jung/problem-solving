-- Replace with your SQL query

select
    date,
    count(*) count,
    (select count(*) from posts where DATE(created_at) <= date) total
from
    (
    select DATE(created_at) date, 1 x
    from posts
    ) pt
group by date
order by date