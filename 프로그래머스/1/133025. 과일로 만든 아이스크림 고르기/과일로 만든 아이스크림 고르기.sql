SELECT fh.flavor 
FROM FIRST_HALF fh
JOIN ICECREAM_INFO ii ON fh.flavor = ii.flavor
WHERE fh.TOTAL_ORDER > 3000 
  AND ii.INGREDIENT_TYPE = 'fruit_based'
ORDER BY fh.TOTAL_ORDER DESC;