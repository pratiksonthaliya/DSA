SELECT Department, Employee, Salary
FROM (
    SELECT 
        d.name AS Department, 
        e.name AS Employee, 
        e.salary,
        MAX(e.salary) OVER (PARTITION BY e.departmentId) AS max_salary
    FROM Department d
    JOIN Employee e
        ON e.departmentId = d.id
) t
WHERE salary = max_salary;