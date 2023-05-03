from bs4 import BeautifulSoup
from urllib.request import urlopen, Request
import pandas as pd
from tqdm import tqdm_notebook
# import tqdm
df = pd.read_csv('best_sandwiches_list_chicago.csv',index_col=0)
# req = Request(
#     df['URL'][0],
#     headers={'User-Agent':'Mozila/5.0'}
# )

# html = urlopen(req)
# soup_tmp = BeautifulSoup(html,"html.parser")
# price_tmp = soup_tmp.find('p','addy').get_text()
# print(soup_tmp.find('p','addy').get_text())

price = []
address = []

for n in tqdm_notebook(df.index):
    req = Request(df['URL'][n], headers={'User-Agent':'Mozila/5.0'})
    html = urlopen(req)
    soup_tmp = BeautifulSoup(html,'lxml')

    gettings = soup_tmp.find('p','addy').get_text()

    price.append(gettings.split()[0][:-1])
    address.append(''.join(gettings.split()[1:-2]))
df['Price'] = price
df['Address'] = address
df = df.loc[:,['Rank','Cafe','Menu','Price','Address']]

df.set_index('Rank',inplace=True)
df.head()
df.to_csv('best_sandwiches_list_chicago2.csv',sep=',',encoding='UTF-8')
