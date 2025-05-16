-- 코드를 입력하세요
-- 입양 게시판에 동물 정보를 게시하려 합니다. 동물의 생물 종, 이름, 성별 및 중성화 여부를 아이디 순으로 조회하는 SQL문을 작성해주세요.
SELECT animal_type , NVL(name , 'No name') as name , sex_upon_intake
from animal_ins
order by animal_id;