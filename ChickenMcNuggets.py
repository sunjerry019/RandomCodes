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
        """
        counts = 1
        nuggets = size * counts
        while nuggets <= n:
            #print("size: {}\tcounts: {}\tnuggets: {}".format(size, counts, nuggets))
            if (nuggets not in arrayOfNuggets) or ((nuggets in arrayOfNuggets) and (counts < sum(arrayOfNuggets[nuggets].values()))):
                arrayOfNuggets[nuggets] = {size : counts}
            counts += 1
            nuggets = size * counts
        """

        arrayOfNuggets[size] = {size: 1}

        for nugs in sorted(arrayOfNuggets): #checking all existing nugget totals
            #if nugs%size: #not a multiple of current size
            #print("Trying {} with {} sized nugs boxes".format(nugs, size))
            total = nugs + size
            if total in arrayOfNuggets: #if such a nugget count alr exists
                if (sum(arrayOfNuggets[nugs].values()) + 1) < sum(arrayOfNuggets[total].values()): #check whether its more optimal
                    cntsOfsize = 1
                    if size in arrayOfNuggets[nugs]: #check whether size alr exists
                        cntsOfsize += arrayOfNuggets[nugs][size]
                    x = {size : cntsOfsize}
                    arrayOfNuggets[total] = {**arrayOfNuggets[nugs], **x}
                #elif (sum(arrayOfNuggets[nugs].values()) + 1) == sum(arrayOfNuggets[total].values()):
                #    print("At size {}: found duplicate solution to {} nuggets: \n{}\n{}".format(size, total, arrayOfNuggets[total], arrayOfNuggets[nugs]))
            else:
                nuggets = nugs
                while ((nuggets + size) <= n): # and ((nuggets + size) not in arrayOfNuggets) #continously add until limit because sorted(arrayOfNuggets) doesnt update
                    total = nuggets + size
                    #print("New solution found while trying for {}: {}".format(size, total))
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
