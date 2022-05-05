select
    *,
    CASE
        WHEN heads > arms THEN 'BEAST'
        WHEN tails > legs THEN 'BEAST'
        ELSE 'WEIRDO'
        END species
from
    top_half a
        join bottom_half b on b.id=a.id
order by species
