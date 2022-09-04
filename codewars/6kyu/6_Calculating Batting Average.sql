select
    player_name,
    games,
    ROUND((hits / at_bats::numeric)::DECIMAL, 3)::TEXT batting_average
from yankees
where at_bats >=100
order by batting_average desc