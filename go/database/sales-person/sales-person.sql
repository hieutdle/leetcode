SELECT s.name
FROM SalesPerson s
WHERE s.name NOT IN (
    SELECT s.name
    FROM SalesPerson s
    JOIN Orders o
    ON s.sales_id = o.sales_id
    JOIN Company c
    ON o.com_id = c.com_id
    WHERE c.name = 'RED'
)

# c.name != 'RED' is not correct because it will also will also retrieve the records if SalesPerson (who have delivered "RED" company order) have delivered any other color order.