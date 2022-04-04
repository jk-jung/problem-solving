select
    c.customer_id,
    email,
    count(*) payments_count,
    sum(amount)::float total_amount
from
    customer c
        join payment p on p.customer_id = c.customer_id
group by c.customer_id
order by total_amount desc
    limit 10