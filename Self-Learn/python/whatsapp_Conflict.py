#!/usr/bin/python3

import os
import platform
import sys
import shutil

ppwd = input("Source: ")
dest = input("Destination: ")

syst = platform.system()

if syst == "Windows":
	ppwd = ppwd if ppwd else "D:\Photos"
	dest = dest if dest else "D:\Photos\Archive"
	delim = "\\"
elif syst == "Linux":
	ppwd = ppwd if ppwd else "/mnt/data/Phones/Sony Xperia Z3/asd/WhatsApp Images_Ori"
	dest = dest if dest else "/mnt/data/Phones/Sony Xperia Z3/asd/WhatsApp Images"
	delim = "/"

copyto = "/mnt/data/Phones/Sony Xperia Z3/asd/delta"

# initialization
listoffiles = []
skipped = 0;

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
        l = copyto + delim + files
        if os.path.exists(dst_file_path):
            new_file_name =  rename(files, dst)
            dst_file_path = dst + new_file_name
            l = copyto + delim + new_file_name

        print ("Copying:", dst_file_path)
        try:
            shutil.copyfile(src_file_path, l)
        except IOError:
            print (src_file_path, "does not exist")
            raw_input("Please, press enter to continue.")

# main code
print("Crawling...")

for (dirpath, dirnames, filenames) in os.walk(ppwd):
	for name in filenames:
		print("At file: ", name)
		datei = dirpath + delim + name
		size = os.path.getsize(datei)
		datem = os.path.getmtime(datei)
		
		destdirPath = dirpath.replace(ppwd, dest)
		datei2 = destdirPath + delim + name
		
		if os.path.exists(destdirPath):
			size2 = os.path.getsize(datei2)
			datem2 = os.path.getmtime(datei2)
			
			if (size == size2) and (datem == datem2):
				skipped += 1
				print("Skipped")
			else:
				listoffiles.append(dirpath.replace(ppwd + delim, "") + name)
				print("Appended")
		else:
			listoffiles.append(name)
			print("Appended")
print("Crawling...Done!")
print("Files skipped:", skipped)

print("Copying")
copy_files(ppwd + delim, dest + delim, listoffiles)
print("Copy Done!")

















