select max(first_actor)  first_actor,
       max(second_actor) second_actor,
       max(title)        title
from film_actor fa
         join film f on f.film_id = fa.film_id
         join (
    select a1.actor_id                              a_id1,
           a2.actor_id                              a_id2,
           concat(a1.first_name, ' ', a1.last_name) first_actor,
           concat(a2.first_name, ' ', a2.last_name) second_actor,
           (
               select count(*)
               from (
                        select film_id,
                               count(*) c
                        from film_actor
                        where actor_id in (a1.actor_id, a2.actor_id)
                        group by film_id
                        having count(*) >= 2
                    ) as temp
           ) as count
    from
        actor a1
        join actor a2
    on a1.actor_id < a2.actor_id
    order by count desc
        limit 1
) as t on fa.actor_id = t.a_id1 or fa.actor_id = t.a_id2
group by f.film_id
having count(*) >= 2
order by title asc