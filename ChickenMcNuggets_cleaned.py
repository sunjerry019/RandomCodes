#!/bin/python3

#Frobenius numbers
import argparse
import sys

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('number', metavar = 'n', help = "Total number of Chicken McNuggets you wish to buy")
    args = parser.parse_args()
    buy(int(args.number))

def buy(n):
    sizeOfBoxesSold = [4, 6, 9, 20]
    arrayOfNuggets = {}

    #base case
    if(n < 4):
        print("Buying of this number of Chicken McNuggets is not possible")
        sys.exit(0)

    for size in sizeOfBoxesSold:

        arrayOfNuggets[size] = {size: 1}

        for nugs in sorted(arrayOfNuggets): #checking all existing nugget totals
            total = nugs + size
            if total in arrayOfNuggets: #if such a nugget count alr exists
                if (sum(arrayOfNuggets[nugs].values()) + 1) < sum(arrayOfNuggets[total].values()): #check whether its more optimal
                    cntsOfsize = 1
                    if size in arrayOfNuggets[nugs]: #check whether size alr exists
                        cntsOfsize += arrayOfNuggets[nugs][size]
                    x = {size : cntsOfsize}
                    arrayOfNuggets[total] = {**arrayOfNuggets[nugs], **x}
            else:
                nuggets = nugs
                while ((nuggets + size) <= n): #continously add until limit because sorted(arrayOfNuggets) doesnt update
                    total = nuggets + size
                    cntsOfsize = 1
                    if size in arrayOfNuggets[nuggets]: #check whether size alr exists
                        cntsOfsize += arrayOfNuggets[nuggets][size]
                    x = {size : cntsOfsize}
                    arrayOfNuggets[total] = {**arrayOfNuggets[nuggets], **x}
                    nuggets += size

    try:
        for size in sorted(arrayOfNuggets[n]):
            print("{} x {} Chicken McNuggets".format(arrayOfNuggets[n][size], size))
    except KeyError:
        print("Buying of this number of Chicken McNuggets is not possible")

main()
