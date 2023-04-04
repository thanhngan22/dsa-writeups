#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumNumber' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. STRING password
#

def minimumNumber(n, password):
    # Return the minimum number of characters to make the password strong
    numbers = "0123456789"
    lower_case = "abcdefghijklmnopqrstuvwxyz"
    upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    special_characters = "!@#$%^&*()-+"
    
    # variables for check
    hasNumber = False;
    hasLower = False;
    hasUpper = False;
    hasSpecial = False;
    
    count = 0;
    
    for c in password:
        if c in upper_case:
            hasUpper = True;
            continue;
        if c in lower_case:
            hasLower = True;
            continue;
        if c in numbers:
            hasNumber = True;
            continue;
        if c in special_characters:
            hasSpecial = True;
    if not hasLower : count += 1
    if not hasNumber : count += 1
    if not hasUpper : count += 1
    if not hasSpecial : count += 1
    
    if n + count < 6 :
        return 6 - n;
    return count;

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    password = input()

    answer = minimumNumber(n, password)

    fptr.write(str(answer) + '\n')

    fptr.close()
