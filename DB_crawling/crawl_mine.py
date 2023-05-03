from bs4 import BeautifulSoup
from urllib.request import urlopen, Request
from urllib.parse import urljoin
import re
import pandas as pd
def parse_price(price):
  a=0
  b=0
  end = 0
  sta = 0
  for i in range(len(price)-1,0):
    if price[i] == '\n' and a==0:
      end = i
      a=1
    if price[i] == ' ' and a==1:
      start = i
  return price[start:end-1] 


url_base = 'https://search.musinsa.com/'
url_sub = "/ranking/best?u_cat_cd="
url = url_base+url_sub

req = Request(
    url,
    headers={'User-Agent':'Mozilla/5.0'}
)

html = urlopen(req)
soup = BeautifulSoup(html,"html.parser")
product_name=[]
price=[]
manufacturer=[]
list_soup = soup.find_all('div','article_info')
product = list_soup[0]
price.append(product.find(class_='price').get_text())
print(price)

# for product in list_soup:

