#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'closestNumbers' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def closestNumbers(arr):
    # Write your code here
    arr.sort()
    min = arr[1] - arr[0]
    res = []
    for i in range(1, len(arr)):
        if arr[i] - arr[i-1] == min:
            res.append(arr[i-1])
            res.append(arr[i])
        elif arr[i] - arr[i-1] < min:
            min = arr[i] - arr[i-1]
            res.clear()
            res.append(arr[i-1])
            res.append(arr[i])
    return res
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = closestNumbers(arr)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
