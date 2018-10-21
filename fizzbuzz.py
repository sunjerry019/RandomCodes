#!/bin/python3

for x in range(1,101):
	output = ""

	if x % 3 == 0:
		output += "fizz"
	if x % 5 == 0:
		output += "buzz"
	if len(output) == 0:
		output = x

	print(output)