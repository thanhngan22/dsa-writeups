#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'pickingNumbers' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY a as parameter.
#

def pickingNumbers(a):
    # Write your code here
    max = 0;
    while len(a) != 0:
        x = a[0];
        count = 0
        count += a.count(x);
        a = [i for i in a if i != x];
        for i in a:
            if abs(i - x) <= 1:
                countI = a.count(i)
                count += countI;
                a = [j for j in a if j != i];
                max = count if count > max else max
                count -= countI;
        max = count if count > max else max
        
    return max;
        
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = pickingNumbers(a)

    fptr.write(str(result) + '\n')

    fptr.close()
