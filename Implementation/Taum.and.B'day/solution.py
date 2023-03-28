#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'taumBday' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER b
#  2. INTEGER w
#  3. INTEGER bc
#  4. INTEGER wc
#  5. INTEGER z
#

def taumBday(b, w, bc, wc, z):
    # Write your code here
    # find max of bc, wc and z
    max = bc if bc > wc else wc;
    max = max if max > z else z;
    
    if max == z :
        return b * bc + w * wc;
    else :
        if bc < wc:
            firstSum = b * bc + w * wc;
            secondSum = b * bc + w * bc + w * z;
            return secondSum if secondSum < firstSum else firstSum;
        else :
            firstSum = b * bc + w * wc;
            secondSum = b * wc + w * wc + b * z;
            return secondSum if secondSum < firstSum else firstSum;
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        b = int(first_multiple_input[0])

        w = int(first_multiple_input[1])

        second_multiple_input = input().rstrip().split()

        bc = int(second_multiple_input[0])

        wc = int(second_multiple_input[1])

        z = int(second_multiple_input[2])

        result = taumBday(b, w, bc, wc, z)

        fptr.write(str(result) + '\n')

    fptr.close()
