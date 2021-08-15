select title from
    (
        select
            title,
            fa.film_id,
            count(*) count
        from
            film_actor fa
            join film f on f.film_id=fa.film_id
        where
            (fa.actor_id = 105 or fa.actor_id = 122)
        group by title, fa.film_id
        having count(*) >= 2
        order by title asc
    ) as t
