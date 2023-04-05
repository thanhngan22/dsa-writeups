#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'alternatingCharacters' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def alternatingCharacters(s):
    # Write your code here
    listFromS = [c for c in s]
    i = 1;
    count = 0
    while i < len(listFromS):
        if listFromS[i] == listFromS[i - 1]:
            listFromS.pop(i);
            count += 1
        else :
            i += 1
    return count
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = alternatingCharacters(s)

        fptr.write(str(result) + '\n')

    fptr.close()
