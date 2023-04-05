#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gemstones' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING_ARRAY arr as parameter.
#

def gemstones(arr):
    # Write your code here
    for i in range(len(arr)):
        arr[i] = set(arr[i])
    count = 0;
    for s in arr[0]:
        isGemstone = True
        for i in range(1, len(arr) ):
            if s not in arr[i]:
                isGemstone = False
                break
        if isGemstone:
            count += 1
    return count
                
        
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr_item = input()
        arr.append(arr_item)

    result = gemstones(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
