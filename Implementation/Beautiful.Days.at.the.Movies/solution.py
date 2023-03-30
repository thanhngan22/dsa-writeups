#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'beautifulDays' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER i
#  2. INTEGER j
#  3. INTEGER k
#

def beautifulDays(i, j, k):
    # Write your code here
    count = 0;
    for x in range (i, j+1):
        copyOfX = x;
        reverseX = 0;
        while copyOfX != 0:
            reverseX = reverseX * 10 + copyOfX % 10;
            copyOfX /= 10
            copyOfX = int(copyOfX)
        kq = abs(x - reverseX) / k;
        if kq == int (kq) : count += 1
    return count;
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    i = int(first_multiple_input[0])

    j = int(first_multiple_input[1])

    k = int(first_multiple_input[2])

    result = beautifulDays(i, j, k)

    fptr.write(str(result) + '\n')

    fptr.close()
