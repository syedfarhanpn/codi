from selenium import webdriver

options = ChromeDrive().setBinary("C:\Program Files\BraveSoftware\Brave-Browser\Application\brave.exe");

driver = webdriver.ChromeOptions(options)

url = "https://s4.wintub.com/"