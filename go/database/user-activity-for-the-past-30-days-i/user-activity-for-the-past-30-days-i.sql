SELECt activity_date as day, count(distinct user_id) as active_users
FROM Activity
GROUP BY day
HAVING DATEDIFF("2019-07-27", day) >= 0 AND  DATEDIFF("2019-07-27", day) < 30
