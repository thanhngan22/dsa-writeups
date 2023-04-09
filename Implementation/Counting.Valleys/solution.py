#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'countingValleys' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER steps
#  2. STRING path
#

def countingValleys(steps, path):
    # Write your code here
    value = 0
    down = False
    valleys = 0
    for c in path:
        if c == 'D':
            value -= 1
        else:
             value += 1
        if down == True and value == 0:
            valleys += 1
        if value < 0:
            down = True
        else:
            down = False
    return valleys
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    steps = int(input().strip())

    path = input()

    result = countingValleys(steps, path)

    fptr.write(str(result) + '\n')

    fptr.close()
