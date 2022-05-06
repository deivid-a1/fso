# import requests
# from requests.auth import HTTPBasicAuth
# import openpyxl

# file_link = "https://docs.google.com/spreadsheets/d/1pv_DzWXGRkm4pimTbJomf_8U2UbzIZ_uTg3y31XqURo/edit#gid=0"
# file = "sheet.xlsx"
# urllib.urlretrive(file_link, file)

import urllib.request
outfilename = "test.xls"
url_of_file = "http://www.muellerindustries.com/uploads/pdf/UW%20SPD0114.xls"
urllib.request.urlretrieve(url_of_file, outfilename)