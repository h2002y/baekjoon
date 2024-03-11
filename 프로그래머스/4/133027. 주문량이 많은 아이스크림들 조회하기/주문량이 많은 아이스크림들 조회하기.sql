WITH J AS (
    SELECT FLAVOR, SUM(TOTAL_ORDER) AS TOTAL_ORDER
    FROM JULY
    GROUP BY FLAVOR
), H AS (
    SELECT FLAVOR, SUM(TOTAL_ORDER) AS TOTAL_ORDER
    FROM FIRST_HALF
    GROUP BY FLAVOR
)

SELECT J.FLAVOR
FROM J INNER JOIN H 
ON J.FLAVOR = H.FLAVOR
ORDER BY (J.TOTAL_ORDER + H.TOTAL_ORDER) DESC LIMIT 3;