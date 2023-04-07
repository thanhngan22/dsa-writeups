#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'superDigit' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING n
#  2. INTEGER k
#

def superDigit(n, k):
    # Write your code here
    if len(n) == 1 and k == 1:
        return ord(n) - ord('0')
    # get the sum of digits
    sumDigits = 0
    temp = n
    while len(temp) != 0:
        tail = len(temp) - 1
        sumDigits += ord(temp[tail]) - ord('0')
        print(f"num: {temp[tail]}")        
        temp = temp[:tail]
    print(f"sum: {sumDigits}")
    return superDigit(str(sumDigits * k), 1)
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = first_multiple_input[0]

    k = int(first_multiple_input[1])

    result = superDigit(n, k)

    fptr.write(str(result) + '\n')

    fptr.close()
