select
    ROW_NUMBER() over (order by sum(p.points) desc) as rank,
        CASE WHEN p.clan != '' THEN p.clan
             ELSE '[no clan specified]'
            END AS clan,
    sum(p.points) total_points,
    count(*) total_people
from people p
group by clan
order by total_points desc