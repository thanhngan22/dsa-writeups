#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'makingAnagrams' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING s1
#  2. STRING s2
#

def makingAnagrams(s1, s2):
    # Write your code here
    chars = set(s1)
    common = []
    for c in chars:
        if c in s2:
            common.append(c)
    nDel = len(s1) + len(s2)
    for c in common:
        count1 = s1.count(c)
        count2 = s2.count(c)
        min = count1 if count1 < count2 else count2
        nDel -= 2 * min
    return nDel

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s1 = input()

    s2 = input()

    result = makingAnagrams(s1, s2)

    fptr.write(str(result) + '\n')

    fptr.close()
