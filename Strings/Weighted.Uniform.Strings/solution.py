#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'weightedUniformStrings' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER_ARRAY queries

#

def weightedUniformStrings(s, queries):
    # Write your code here
    prevWeight = 0;
    weights = set()
    i = 0
    while i < len(s):
        j = i
        while j < len(s) and s[j] == s[i]:
            weight = (ord(s[i]) - 96) * (j - i + 1)
            weights.add(weight)
            j += 1
        i = j
    
    res = []
    # check the queries
    for i in queries:
        if i in weights:
            res.append('Yes')
        else:
            res.append('No')
    return res
#

def weightedUniformStrings_RT(s, queries):
    # Write your code here
    list = []
    prevChar = ''
    for c in s:
        if c < 'a' or c > 'z':
            continue;
        if c == prevChar:
            temp = list[len(list) - 1] + c;
            list.append(temp);
        else:
            list.append(c);
        prevChar = c;
        
    # calculate the weight:
    Weight = []
    for temp in list:
        code = ord(temp[0]) - 96;
        w = code;
        if len(temp) > 1:
            w = code * len(temp)
        Weight.append(w)
    # print(f"list: {list}")
    # print(f"weight: {Weight}")
    Weight = set(Weight)
    
    res = []
    # check the queries
    for i in queries:
        if i in Weight:
            res.append('Yes')
        else:
            res.append('No')
    return res
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    queries_count = int(input().strip())

    queries = []

    for _ in range(queries_count):
        queries_item = int(input().strip())
        queries.append(queries_item)

    result = weightedUniformStrings(s, queries)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
