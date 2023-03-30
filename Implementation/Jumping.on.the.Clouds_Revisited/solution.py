#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c, k):
    E = 100;
    index = 0;
    while 1 :
        index = (index + k) % (len(c));
        if index == 0:
            if c[0] == 1: E-= 3
            else: E -= 1;
            break;
        if c[index] == 1: E -= 3;
        else : E -= 1;
    return E

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c, k)

    fptr.write(str(result) + '\n')

    fptr.close()
