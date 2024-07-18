SELECT name AS Customers
FROM Customers c
LEFT OUTER JOIN Orders o
ON c.id = o.customerId
WHERE o.id IS NULL
