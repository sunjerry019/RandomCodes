#!/usr/bin/python3

import os
import platform
import sys
import shutil

ppwd = input("Enter location of files to be archived: ")
dest = input("Enter archive location: ")

syst = platform.system()

if syst == "Windows":
	ppwd = ppwd if ppwd else "D:\Photos"
	dest = dest if dest else "D:\Photos\Archive"
	delim = "\\"
elif syst == "Linux":
	ppwd = ppwd if ppwd else "/mnt/data/Photos"
	dest = dest if dest else "/mnt/data/Archive"
	delim = "/"

# initialization
maxStorage = 4.7 * (10**9)
photos = {}
bins = []
binsNames = []
total = 0

# functions
def rename(file_name, dst, num=1):
    # splits file name to add number distinction
    (file_prefix, extension) = os.path.splitext(file_name)
    renamed = "%s(%d)%s" % (file_prefix, num, extension)

    # checks if renamed file exists. Renames file if it does exist.
    if os.path.exists(dst + renamed):
        return rename(file_name, dst, num + 1)
    else:
        return renamed

def copy_files(src, dst ,file_list):
    for files in file_list:
        src_file_path = src + files
        dst_file_path = dst + files
        if os.path.exists(dst_file_path):
            new_file_name =  rename(files, dst)
            dst_file_path = dst + new_file_name

        print ("Copying:",dst_file_path)
        try:
            shutil.copyfile(src_file_path,dst_file_path)
        except IOError:
            print (src_file_path, "does not exist")
            raw_input("Please, press enter to continue.")

# main code
print("Crawling...")

for (dirpath, dirnames, filenames) in os.walk(ppwd):
	for name in filenames:
		datei = dirpath + delim +  name;
		size = os.path.getsize(datei)
		photos[datei] = size;
		# print(datei.encode('ascii', 'replace').decode("ascii", "replace"), size);
print("Crawling...Done!")

sorted_photos = sorted(photos, key=photos.get, reverse=True)

print("Packing the bins...")
for filename in sorted_photos:
	foundaplace = 0
	for b in range(len(bins)):
		if (bins[b] + photos[filename]) <= maxStorage:
			foundaplace = 1
			bins[b] += photos[filename]
			binsNames[b].append(filename)
	if (foundaplace == 0):
		bins.append(photos[filename])
		binsNames.append([filename])
print("Packing the bins...Done!\n")
print("Results:")

for b in range(len(bins)):
	total += bins[b]
	print("Bin", b, ":", bins[b], "| % Full:", ((bins[b]/maxStorage)*100))

print("Total Archive:", (total/(10**9)) , "GB")
