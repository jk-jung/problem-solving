SELECT
    j.job_title,
    round((SUM(j.salary) / COUNT(p)),2)::float as average_salary,
    COUNT(p.id) as total_people,
    round(SUM(j.salary),2)::float as total_salary
FROM people p
         JOIN job j on j.people_id = p.id
GROUP BY j.job_title
ORDER BY average_salary desc
