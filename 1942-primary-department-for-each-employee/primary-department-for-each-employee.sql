-- Employees with only one department
SELECT employee_id, department_id
FROM Employee
GROUP BY employee_id
HAVING COUNT(department_id) = 1

UNION

-- Employees with multiple departments and primary flag
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y'