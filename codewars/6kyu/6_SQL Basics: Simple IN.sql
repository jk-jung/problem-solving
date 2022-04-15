select
    d.id,
    d.name
from
    departments d
where id in (select department_id as id from sales where price > 98 and d.id = department_id )