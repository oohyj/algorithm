-- 코드를 작성해주세        
SELECT 
CONCAT(QUARTER(DIFFERENTIATION_DATE) , 'Q') AS QUARTER , 
COUNT(*) AS ECOLI_COUNT
FROM ECOLI_DATA
GROUP BY QUARTER
ORDER BY QUARTER ASC;