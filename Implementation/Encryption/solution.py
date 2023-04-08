#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'encryption' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def encryption(s):
    # Write your code here
    # ignore the space if has
    newS = [c for c in s if c != ' ']
    row = math.floor(math.sqrt(len(newS))) 
    col = math.ceil(math.sqrt(len(newS)))
    if row * col < len(newS):
        row = col
    arr = []
    for i in range(row):
        arrRow = []
        for j in range(col) :
            if i * col + j >= len(newS):
                break
            arrRow.append(newS[i * col + j])
        arr.append(arrRow)
    res = []
    for j in range(col) :
        for i in range(row):
            if i * col + j >= len(newS):
                break
            res.append(arr[i][j])
        res.append(' ')
    return ''.join(res)  

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = encryption(s)

    fptr.write(result + '\n')

    fptr.close()
