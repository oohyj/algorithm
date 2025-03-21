-- 코드를 입력하세요
SELECT ri.REST_ID , REST_NAME , FOOD_TYPE , FAVORITES , ADDRESS, round(avg(REVIEW_SCORE), 2) AS SCORE
FROM REST_INFO ri
JOIN REST_REVIEW rr on ri.REST_ID = rr.REST_ID
where ADDRESS LIKE '서울%'
group by ri.REST_ID
order by score desc , favorites desc;