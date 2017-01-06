#!/usr/bin/python3

"""
distanceFare.py
Calculate possible combinations of fares paid on the Singaporean transport network to find ways to maximize a given amount of money in a card.
Assumes only normal services (i.e. no express services)

Aims to minimize loss on the card. 

2017-01-01
"""

import argparse
import sys
from collections import Counter

def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('value', metavar = 'n', help = "Stored value in the EZ-Link Card in cents")
	args = parser.parse_args()
	fares(int(args.value))

def out(methode):
	output = []
	for fare in sorted(methode):
		output.append("{} x {} cents".format(methode[fare], fare))
	return ", ".join(output)

def fares(n):
	faresPerRide = [77, 87, 97, 107, 116, 123, 129, 133, 137, 141, 145, 149, 153, 157, 161, 165, 169, 172, 175, 178, 181, 183, 185, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202]
	# has to be sorted (actually probably not)

	# init costs
	costs = {0: [Counter({})]}

	# base case
	if n < 77:
		print("Stored value on the card is too low. Perhaps a top up of 5 dollars might help in the calculations.")
		sys.exit(0)
	else:
		for x in range(faresPerRide[0], n+1):
			# check if we can add to any existing cost
			for cost in list(sorted(costs)):
				if (x - cost) in faresPerRide:
					newobj = Counter({(x - cost) : 1})
					# add to costs[x]
					if x not in costs:
						costs[x] = [way + newobj for way in costs[cost]]
					else:
						for way in costs[cost]:
							costs[x].append(way + newobj)

					# remove duplicates
					eigenartig = []
					for meth in costs[x]:
						if meth not in eigenartig:
							eigenartig.append(meth)
					costs[x] = eigenartig

	for x in reversed(range(77,n+1)):
		if x in costs:
			diff = n - x
			if diff < faresPerRide[0]:
				print("{} cent(s) loss:".format(diff))
				for method in costs[x]:
					print("\t{}".format(out(method)))

main()

"""
for fare in faresPerRide:
			currentFare = 0
			while (currentFare + fare) <= n:
				nf = currentFare + fare

				newobj = Counter({fare : 1})

				if nf not in costs:
					costs[nf] = [way + newobj for way in costs[currentFare]]
				else:
					
				currentFare = nf
"""