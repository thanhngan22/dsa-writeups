#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'kaprekarNumbers' function below.
#
# The function accepts following parameters:
#  1. INTEGER p
#  2. INTEGER q
#

def kaprekarNumbers(p, q):
    # Write your code here
    res = []
    for num in range(p, q + 1):
        # get num digits of num
        d = 0
        temp = num
        while temp != 0:
            d += 1
            temp = int(temp/10)
        
        square = num * num;
        # get the num digits of square
        dSq = 0
        while temp != 0:
            dSq += 1
            temp = int(temp/10)
        numStr = str(square)
        
        left = numStr[:dSq - d]
        right = numStr[dSq-d :]
        if left == '':
            left = '0'
        if int(left ) + int(right) == num:
            res.append(num)
    if len(res) == 0:
        print('INVALID RANGE')
    else:
        for x in res:
            print(x, end=' ')
    

if __name__ == '__main__':
    p = int(input().strip())

    q = int(input().strip())

    kaprekarNumbers(p, q)
