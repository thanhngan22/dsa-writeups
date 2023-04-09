#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumDistances' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY a as parameter.
#

def minimumDistances(a):
    # Write your code here
    min = -1
    for i in range(len(a) -1):
        for j in range(i+1,len(a)):
            if a[i] == a[j]:
                if min == -1:
                    min = j - i
                else:
                    min = j - i if j - i < min else min
            if min == 1:
                return min
    return min

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = minimumDistances(a)

    fptr.write(str(result) + '\n')

    fptr.close()

