#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'missingCharacters' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def missingCharacters(s):
    # Write your code here
    listChars = [0] * 26
    listNumbers = [0] * 10
    for c in s:
        if c.isalpha():
            listChars[ord(c) - ord('a')] += 1
        else :
            listNumbers[ord(c) - ord('0')] += 1
    rest = []
    for index in range(len(listNumbers)):
        if  listNumbers[index] == 0:
            rest.append(str(index))
    for index in range(len(listChars)):
        if listChars[index] == 0:
            rest.append(chr(index + ord('a')))
    return ''.join(rest)
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = missingCharacters(s)

    fptr.write(result + '\n')

    fptr.close()
