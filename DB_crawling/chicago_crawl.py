from bs4 import BeautifulSoup
from urllib.request import urlopen, Request
from urllib.parse import urljoin
import re
import pandas as pd

url_base = 'https://www.chicagomag.com'
url_sub = "/Chicago-Magazine/November-2012/Best-Sandwiches-Chicago/"
url = url_base+url_sub

req = Request(
    url,
    headers={'User-Agent':'Mozilla/5.0'}
)

html = urlopen(req)
soup = BeautifulSoup(html,"html.parser")
# print(len(soup.find_all('div','sammy')))

# print(soup.find_all('div','sammy')[0])

rank=[]
main_menu = []
cafe_name = []
url_add = []

list_soup = soup.find_all('div','sammy')

for item in list_soup:
    rank.append(item.find(class_='sammyRank').get_text())

    tmp_string = item.find(class_='sammyListing').get_text()

    main_menu.append(re.split(('\n|\r\n'), tmp_string)[0])
    cafe_name.append(re.split(('\n|\r\n'), tmp_string)[1])
    url_add.append(urljoin(url_base,item.find('a')['href']))

data = {'Rank':rank,'Menu':main_menu,'Cafe':cafe_name,'URL':url_add}
df = pd.DataFrame(data)
print(df.head())
# print(cafe_name)
