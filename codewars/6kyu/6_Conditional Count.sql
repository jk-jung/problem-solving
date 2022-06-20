select
    EXTRACT(MONTH FROM payment_date) AS month,
  count(*) total_count,
  sum(amount) total_amount,
  count(*) FILTER (WHERE staff_id = 1) mike_count,
  sum(amount) FILTER (WHERE staff_id = 1) mike_amount,
  count(*) FILTER (WHERE staff_id = 2) jon_count,
  sum(amount) FILTER (WHERE staff_id = 2) jon_amount
from payment
group by month
order by month