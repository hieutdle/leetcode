SELECT e.employee_id
FROM Employees e
LEFT OUTER JOIN Salaries s
ON e.employee_id = s.employee_id
WHERE s.salary IS NULL
UNION
SELECT s.employee_id
FROM Employees e
RIGHT OUTER JOIN Salaries s
ON e.employee_id = s.employee_id
WHERE e.name IS NULL
ORDER BY employee_id