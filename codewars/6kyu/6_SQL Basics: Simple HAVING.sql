select
    age,
    count(*) total_people
from
    people
group by age
having count(*) >= 10s