from bs4 import BeautifulSoup

page = open("test_first.html",'r').read()
soup = BeautifulSoup(page,'html.parser')

# print(soup.prettify())

# print(list(soup.children))

html = list(soup.children)[2]
# print(html)

# print(list(html.children))

body = list(html.children)[3]
# print(body)

# print(list(body.children))

# print(list(body.children)[1])

# print(soup.find_all('p'))

# print(soup.find_all('p',class_='outer-text'))

for each_tag in soup.find_all('p'):
    print(each_tag.get_text())
