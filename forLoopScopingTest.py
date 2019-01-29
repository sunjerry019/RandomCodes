#!/usr/bin/env python3

import gc

def method1():
    i = 3
    def x():
        for i in range(100):
            pass
    x()
    print(i)

def method2():
    for i in range(100):
            pass
    del i
    print(i)

method2()
