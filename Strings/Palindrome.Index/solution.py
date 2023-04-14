#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'palindromeIndex' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def isPalindrome(s):
    print(f"s: {s}")
    num = int((len(s) - 1 )/ 2)
    n = len(s)
    for k in range(0, num):
        if s[k] != s[n-1-k]:
            return False
    return True

def palindromeIndex(s):
    # Write your code here
    index = -1
    num = int((len(s) - 1)/2)
    n = len(s)
    
    for k in range(0, num):
        if s[k] != s[n-1-k]: 
            temp = []
            temp[0:k] = s[0:k]
            temp[k:n-1] = s[k+1:n]
            if (isPalindrome(temp)):
                index = k;
            else :
                temp[0:n-1-k] = s[0:n-1-k];
                temp[n-1-k:n-1] = s[n-k:n]
                if (isPalindrome(temp)):
                    index = n-1-k
            break;
            
            
    return index
            
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = palindromeIndex(s)

        fptr.write(str(result) + '\n')

    fptr.close()
