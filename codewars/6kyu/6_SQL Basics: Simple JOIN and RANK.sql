select
    p.*,
    count(*) sale_count,
    RANK() OVER (ORDER BY count(*) DESC) sale_rank
from
    people p
        join sales s on s.people_id=p.id
group by p.id
order by sale_count desc