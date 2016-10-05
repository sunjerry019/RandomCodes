#!/bin/python3

import pycurl
import sys

class Storage:
    def __init__(self):
        self.contents = ''
        self.line = 0

    def store(self, buf):
        self.line = self.line + 1
        self.contents = "%s%i: %s" % (self.contents, self.line, buf)

    def __str__(self):
        return self.contents

def url(url):
    retrieved_body = Storage()
    retrieved_headers = Storage()
    c = pycurl.Curl()
    c.setopt(c.URL, url)
    c.setopt(c.WRITEFUNCTION, retrieved_body.store)
    c.setopt(c.HEADERFUNCTION, retrieved_headers.store)
    c.perform()
    c.close()
    return (retrieved_headers, retrieved_body)

(a, b) = url("http://madasfasdfasdfsafas.blogspot.sg/")
print(a)
