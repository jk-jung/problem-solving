WITH special_sales (id, name) AS (
    SELECT d.id, d.name
    FROM departments d
             JOIN sales s on d.id=s.department_id
    WHERE s.price >= 90
)
SELECT distinct(id), name
FROM special_sales
ORDER BY id