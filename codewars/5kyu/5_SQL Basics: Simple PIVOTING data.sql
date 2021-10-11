CREATE EXTENSION tablefunc;

select *
from crosstab('
  select name as rowid, detail, count(*) as value
  from products p
       join details d on d.product_id=p.id
  group by name, detail
  order by name',
  'select distinct detail from details order by detail'
) as ct(name text, bad integer, good integer, ok integer);