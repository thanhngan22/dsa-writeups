#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'appendAndDelete' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING s
#  2. STRING t
#  3. INTEGER k
#

# def appendAndDelete(s, t, k):
#     # Write your code here
#     lenSrc = len(s);
#     lenDest = len(t);
    
#     # if both string are null
#     if lenSrc == 0 and lenDest == 0: return 'Yes'

#     # if dest string has upper case
#     for x in t:
#         if x.isupper() : return 'No'
    
#     # get min and max length of string
#     minLen = lenSrc if lenSrc < lenDest else lenDest;
#     maxLen = lenSrc if lenSrc > lenDest else lenDest;
    
#     # the first index that two string is diff
#     indexStartDiff = -1;
#     for i in range (0, minLen):
#         if s[i] != t[i]:
#             indexStartDiff = i;
#             break;
#     if indexStartDiff == -1 and lenSrc == lenDest : 
#         # two string is same
#         if k % 2 == 0 or k > 2 * minLen : return 'Yes';
#     if indexStartDiff == -1 and lenSrc != lenDest:
#         indexStartDiff = minLen;
#     leftLen = indexStartDiff
#     if leftLen == 0 and k >= maxLen: return 'Yes'
    
#     numStepDelete = lenSrc - indexStartDiff;
#     numStepAppend = lenDest - indexStartDiff;
#     minNumStepToDo = numStepDelete + numStepAppend;
    
#     if minNumStepToDo == k : return 'Yes'
#     if minNumStepToDo > k : return 'No'

#     if (k - minNumStepToDo) % 2 == 0: return 'Yes'
#     return 'No'
    
def appendAndDelete(s, t, k):
    # get the length of the strings
    len_s = len(s)
    len_t = len(t)

    # handle the case where the target string is longer than the source string plus k
    if len_s + len_t <= k:
        return 'Yes'

    # count the number of common prefix characters between the strings
    common = 0
    while common < len_s and common < len_t and s[common] == t[common]:
        common += 1

    # calculate the minimum number of steps required to convert the source string to the target string
    min_steps = len_s + len_t - 2 * common

    # handle the case where k is greater than or equal to the minimum number of steps required
    if k >= min_steps and (k - min_steps) % 2 == 0:
        return 'Yes'

    return 'No'


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    t = input()

    k = int(input().strip())

    result = appendAndDelete(s, t, k)

    fptr.write(result + '\n')

    fptr.close()
