#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'funnyString' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def funnyString(s):
    # Write your code here
    reverse = [s[i] for i in range(len(s) - 1, -1, -1)]
    codeS = []
    for c in s:
        codeS.append(ord(c))
    codeR = []
    for c in reverse:
        codeR.append(ord(c))
    diffR = []
    diffS = []
    i = 1
    while i < len(s) :
        diffR.append(abs(codeR[i] - codeR[i - 1]));
        diffS.append(abs(codeS[i] - codeS[i - 1]));
        i += 1
    for i in range(len(s) - 1):
        if diffR[i] != diffS[i]:
            return 'Not Funny'
    return 'Funny'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = funnyString(s)

        fptr.write(result + '\n')

    fptr.close()
