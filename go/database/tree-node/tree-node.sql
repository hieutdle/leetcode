SELECT id,
       CASE
           WHEN p_id IS NULL THEN "Root"
           WHEN id IN (SELECT distinct p_id FROM tree) THEN "Inner"
           ELSE "Leaf"
           END as type
FROM Tree