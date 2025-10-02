SELECT concat('/home/grep/src/' , f.board_id , '/' ,f.file_id , f.file_name , f.file_ext) as FILE_PATH
from used_goods_file f
where f.board_id = (
    select b.board_id
    from used_goods_board b
    order by b.views desc
    limit 1
)
order by f.file_id desc;