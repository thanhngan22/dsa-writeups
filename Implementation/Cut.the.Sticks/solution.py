#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'cutTheSticks' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def cutTheSticks(arr):
    # Write your code here
    res = []
    res.append(len(arr))
    while len(arr) != 0:
        min = arr[0]        
        for x in arr: 
            min = x if min > x else min;
        arr = [ i - min for i in arr ]
        arr = [ i for i in arr if i != 0]
        res.append(len(arr))
    res.pop(len(arr) - 1)
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = cutTheSticks(arr)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
