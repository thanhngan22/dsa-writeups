#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'alternate' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def alternate(s):
    # Write your code here
    chars = set(s) #distinct characters
    
    max_len = 0;
    
    for c1 in chars:
        for c2 in chars:
            if c1 != c2:
                temp = [c for c in s if c == c1 or c == c2]
                
                # check whether it is alternated letters
                if all(temp[i] != temp[i+1] for i in range(len(temp) - 1)):
                    max_len = max(max_len, len(temp))
    return max_len

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    l = int(input().strip())

    s = input()

    result = alternate(s)

    fptr.write(str(result) + '\n')

    fptr.close()
