#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'anagram' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def anagram(s):
    # Write your code here
    if len(s) % 2 == 1:
        return -1
    lenSub = int (len(s) / 2)
    sub1 = s[:lenSub]
    sub2 = s[lenSub:]
    chars = set(sub2)
    count = lenSub
    for c in chars:
        if c in sub1:
            count1 = sub1.count(c)
            count2 = sub2.count(c)
            if count1 < count2:
                count -= count1
            else:
                count -= count2
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = anagram(s)

        fptr.write(str(result) + '\n')

    fptr.close()
