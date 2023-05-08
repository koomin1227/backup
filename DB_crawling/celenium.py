from selenium import webdriver
from selenium.webdriver.common.by import By
import time
from tqdm import tqdm

driver = webdriver.Chrome('chromedriver')
driver.get("http://www.opinet.co.kr/searRgSelect.do")

gu_list_raw = driver.find_element(By.XPATH,"""//*[@id="SIGUNGU_NM0"]""")
gu_list = gu_list_raw.find_elements(By.TAG_NAME,"option")

gu_names = [option.get_attribute("value") for option in gu_list]

gu_names.remove('')

for gu in tqdm(gu_names):   
    element = driver.find_element(By.ID,"SIGUNGU_NM0")
    element.send_keys(gu)
    time.sleep(2)

    xpath = """//*[@id="searRgSelect"]"""
    element_sel_gu = driver.find_element(By.XPATH, xpath).click()

    xpath = """//*[@id="glopopd_excel"]"""
    element_get_excel = driver.find_element(By.XPATH,xpath).click()
    time.sleep(1)

driver.close()
# print(gu_names)
