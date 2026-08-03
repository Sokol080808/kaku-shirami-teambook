import os
import string
#import shutil
for f in string.ascii_uppercase:
    #shutil.rmtree(f)
    os.mkdir(f)
    os.system(f"cp main.cpp bld.py {f}")
# bld.py
import os
import sys
os.system(f"g++ -std=c++17 -g -DLOCAL -o {sys.argv[1]} {sys.argv[1]}.cpp")
