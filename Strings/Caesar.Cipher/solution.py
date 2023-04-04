#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'caesarCipher' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER k
#

def caesarCipher(s, k):
    # Write your code here
    res = []
    for c in s:
        if c.isalpha():
            code = ord(c) + k;
            # rotate
            if 'A' <= c <= 'Z' : code = (code - 65) % 26 + 65;
            if 'a' <= c <= 'z' : code = (code - 97) % 26 + 97;
            res.append(chr(code));
        else :
            res.append(c);
    return ''.join(res)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = input()

    k = int(input().strip())

    result = caesarCipher(s, k)

    fptr.write(result + '\n')

    fptr.close()
