#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gameOfThrones' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def gameOfThrones(s):
    # Write your code here
    chars = set(s)
    countC = []
    for item in chars:
        countC.append(s.count(item))
    odd = 0
    even = 0
    for c in countC:
        if c % 2 == 0:
            odd += 1
        else:
            even += 1
    if odd == len(chars):
        return 'YES'
    if even == 1 and len(s) % 2 == 1:
        return 'YES'
    return 'NO'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = gameOfThrones(s)

    fptr.write(result + '\n')

    fptr.close()
