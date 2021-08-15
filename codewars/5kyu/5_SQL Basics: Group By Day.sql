select
    count(*),
    DATE(created_at) AS day,
    description
from
    events
where
    name='trained'
group by day, description