#!/usr/bin/env python3

from timeit import timeit
import time
import math

N = 1
iterations = 10000000

print("Logarithm")
start = time.time()
for i in range(iterations):
	x = math.floor(math.log10(N)) + 1
end = time.time()
print("x = {}, time taken = {}s/cycle".format(x, (end - start)/iterations))


print("String Casting")
start = time.time()
for i in range(iterations):
	x = len(str(N))
end = time.time()
print("x = {}, time taken = {}s/cycle".format(x, (end - start)/iterations))