import pymysql
import pandas as pd
import matplotlib.pyplot as plt
conn = pymysql.connect(host='localhost',user='root',password='namyang0728',db='cookdb',charset='utf8')
cur = conn.cursor()
# query = '김'
# sql = 'select O.item_id as \'상품아이디\' , I.product_name as \'상품이름\', sum(O.sales) as \'상품매출\' from order_info O inner join item I on  O.item_id = I.item_id group by O.item_id order by sum(O.sales) desc'
# cur.execute(sql)
# row = cur.fetchall()
# Dataname = ['id','item','sales']
# result  = pd.DataFrame(row, columns=Dataname)
# result.dtypes
# result = result.astype({'sales':'int'})

# plt.bar(result['item'], result['sales'])
# plt.ticklabel_format(axis="y", style='plain')
# plt.xticks(rotation = 45)
# plt.ylim([0,10000000])
# print(result)

sql = 'insert into usertbl values(\'PNR\',\'박나래\',1985,\'서울\',\'010\',\'12123434\',149,null)'
cur.execute(sql)
conn.commit()
conn.close