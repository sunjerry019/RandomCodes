#!/usr/bin/python3

"""
https.py
Tries to retrieve https://www.bbdc.sg/bbdc/bbdc_web/newheader.asp

2017-01-06
"""

import http.client
import ssl

ctx = ssl.SSLContext(ssl.PROTOCOL_TLSv1)

c = http.client.HTTPSConnection("www.bbdc.sg", context=ctx)
c.request("GET", "/bbdc/bbdc_web/newheader.asp")

response = c.getresponse()
print(response.status, response.reason)

data = response.read()

print(data)