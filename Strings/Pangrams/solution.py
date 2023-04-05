#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'pangrams' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def pangrams(s):
    # Write your code here\
    text = []
    for c in s:
        if ord(c) == 32:
            continue
        if 'A' <= c <= 'Z':
            text.append(chr(ord(c) + 32)) # convert into lower case
        else:
            text.append(c)
    # print(f"text: {text}" )
    setChar = set(text)
    # print(f"set: {setChar}")
    if len(setChar) == 26:
        return 'pangram'
    return 'not pangram'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = pangrams(s)

    fptr.write(result + '\n')

    fptr.close()
