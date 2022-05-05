select *, 'US' as "location"
from ussales
where price > 50
UNION ALL
select *, 'EU' as "location"
from eusales
where price > 50