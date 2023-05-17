use cookdb;
-- 1.
select count(*) as "전체주문건", sum(sales) as "총매출", avg(sales) as "평균매출", max(sales) as "최고매출", min(sales) as "최저매출" from order_info;
-- 2.
select count(*) as "총판매량", sum(sales) as "총매출", sum(if((ITEM_ID = 'M0001' and (CANCEL = 'N')),1,0)) as '전용상품_판매량', sum(if((ITEM_ID = 'M0001' and (CANCEL = 'N')),sales,0)) as '전용상품_매출' 
	from order_info O inner join reservation R on  O.reserv_no = R.reserv_no;
-- 3.
select O.item_id as '상품아이디' , I.product_name as '상품이름', sum(O.sales) as '상품매출' from order_info O inner join item I on  O.item_id = I.item_id group by O.item_id order by sum(O.sales) desc;
