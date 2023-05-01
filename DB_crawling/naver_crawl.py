from bs4 import BeautifulSoup
from urllib.request import urlopen

url = "https://finance.naver.com/marketindex/"

page = urlopen(url)

soup = BeautifulSoup(page,"html.parser")

# print(soup.prettify())

value = soup.find_all('span','value')

value_string = soup.find_all('span','value')[0].string

print(value)
print(value_string)
