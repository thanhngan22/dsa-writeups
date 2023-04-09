#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'workbook' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER k
#  3. INTEGER_ARRAY arr
#

def workbook(n, k, arr):
    # Write your code here
    page = 1
    count = 0
    for i in range(n):
        problems = arr[i]
        if problems <= k:
            if 1 <= page <= problems:
                count += 1
            page += 1
        else:
            mark = 1
            while mark <= problems:
                max = mark + k if mark + k <= problems else problems + 1
                if mark <= page < max:
                    count += 1
                page += 1
                mark += k 
    return count
                
            
        
        
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    result = workbook(n, k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
