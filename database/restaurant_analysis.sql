use cookdb;
-- 1.
select count(*) as "전체주문건", sum(sales) as "총매출", avg(sales) as "평균매출", max(sales) as "최고매출", min(sales) as "최저매출" from order_info;
-- 2.
select count(*) as "총판매량", sum(sales) as "총매출", sum(if((ITEM_ID = 'M0001' and (CANCEL = 'N')),1,0)) as '전용상품_판매량', sum(if((ITEM_ID = 'M0001' and (CANCEL = 'N')),sales,0)) as '전용상품_매출' 
	from order_info O inner join reservation R on  O.reserv_no = R.reserv_no;
-- 3.
select O.item_id as '상품아이디' , I.product_name as '상품이름', sum(O.sales) as '상품매출' from order_info O inner join item I on  O.item_id = I.item_id group by O.item_id order by sum(O.sales) desc;

-- 4.
select substr(R.reserv_date,1,6) as '매출월',
	sum(if(O.item_id = 'M0001',sales,0)) as 'SPECIAL_SET',
    sum(if(O.item_id = 'M0002',sales,0)) as 'PASTA',
    sum(if(O.item_id = 'M0003',sales,0)) as 'PIZZA',
    sum(if(O.item_id = 'M0004',sales,0)) as 'SEA_FOOD',
    sum(if(O.item_id = 'M0005',sales,0)) as 'STEAK',
    sum(if(O.item_id = 'M0006',sales,0)) as 'SALAD_BAR',
    sum(if(O.item_id = 'M0007',sales,0)) as 'SALAD',
    sum(if(O.item_id = 'M0008',sales,0)) as 'SANDWICH',
    sum(if(O.item_id = 'M0009',sales,0)) as 'WINE',
    sum(if(O.item_id = 'M0010',sales,0)) as 'JUICE'
 from reservation R inner join order_info O on R.reserv_no = O.reserv_no group by substr(R.reserv_date,1,6);

-- 5.
select substr(R.reserv_date,1,6) as '매출월', sum(sales) as '총매출', sum(if(O.item_id = 'M0001',sales,0)) as '전용상품매출' from reservation R inner join order_info O on R.reserv_no = O.reserv_no group by substr(R.reserv_date,1,6);

-- 6.
select substr(R.reserv_date,1,6) as '매출월', 
	sum(sales) as '총매출', 
    sum(if(O.item_id = 'M0001',sales,0)) as '전용상품매출',
    round(sum(if(O.item_id = 'M0001',sales,0)) / sum(sales) *100,1) as '매출기여율'
    
    from reservation R inner join order_info O on R.reserv_no = O.reserv_no group by substr(R.reserv_date,1,6);

-- 7.
select substr(R.reserv_date,1,6) as '매출월', 
	sum(sales) as '총매출', 
    sum(if(O.item_id = 'M0001',0,sales)) as '전용상품외매출',
    sum(if(O.item_id = 'M0001',sales,0)) as '전용상품매출',
    concat(round(sum(if(O.item_id = 'M0001',sales,0)) / sum(sales) *100,1),'%') as '전용상품판매율',
    count(*) as '총예약건',
    sum(if(R.cancel = 'N',1,0)) as '예약완료건',
    sum(if(R.cancel = 'Y',1,0)) as '예약취소건',
    from reservation R left join order_info O on R.reserv_no = O.reserv_no group by substr(R.reserv_date,1,6);

-- 8.
select substr(R.reserv_date,1,6) as '매출월', 
	sum(sales) as '총매출', 
    sum(if(O.item_id = 'M0001',0,sales)) as '전용상품외매출',
    sum(if(O.item_id = 'M0001',sales,0)) as '전용상품매출',
    concat(round(sum(if(O.item_id = 'M0001',sales,0)) / sum(sales) *100,1),'%') as '전용상품판매율',
    count(*) as '총예약건',
    sum(if(R.cancel = 'N',1,0)) as '예약완료건',
    sum(if(R.cancel = 'Y',1,0)) as '예약취소건',
    concat(round(sum(if(R.cancel = 'Y',1,0))*100 / count(*),1),'%') as '예약취소율'
    from reservation R left join order_info O on R.reserv_no = O.reserv_no group by substr(R.reserv_date,1,6);

select * from order_info;
select * from reservation;
select * from item;
