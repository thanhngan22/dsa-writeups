#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'repeatedString' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. STRING s
#  2. LONG_INTEGER n
#

def repeatedString(s, n):
    # Write your code here
    lenS = len(s)
    k = int (n / lenS)
    posA = [i + 1 for i in range(lenS) if s[i] == 'a']
    modLen = n % lenS
    count = 0
    for i in range(1, modLen + 1) :
        if i in posA :
            count += 1
    numA = len(posA) * k + count
    return numA

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input().strip())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()
