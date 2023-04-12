#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'biggerIsGreater' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING w as parameter.
#

def biggerIsGreater(w):
    # find the index i where w[i] < w[j] for some j > i
    i = len(w) - 2
    while i >= 0 and w[i] >= w[i+1]:
        i -= 1
    if i < 0:
        return 'no answer'

    # find the index j where w[i] < w[j] and w[j] is minimum after i
    j = len(w) - 1
    while j > i and w[j] <= w[i]:
        j -= 1

    # swap w[i] and w[j]
    w = list(w)
    w[i], w[j] = w[j], w[i]

    # reverse the substring after i
    w[i+1:] = reversed(w[i+1:])

    return ''.join(w)

def biggerIsGreater_wrong(w):
    # Write your code here
    
    # distinctC = set(w);
    # if distinctC.size() == 1:
    #     return 'no answer';

    # find the first index that w[i] < w[j] from the end of string
    index = -1
    for i in range(len(w)-1, -1, -1):
        if w[i-1] < w[i]:
            index = i-1
            break
    if index == -1:
        return 'no answer';
    # find the min character that bigger enough after index in string to swap
    minIndex = -1
    minVal = 0
    for i in range(index + 1, len(w)):
        if w[i] > w[index] :
            if minIndex == -1:
                minVal = ord(w[i]) - ord(w[index])
                minIndex = i
            elif minVal > ord(w[i]) - ord(w[index]):
                minVal = ord(w[i]) - ord(w[index])
                minIndex = i
            
    listFromW = list(w)
    temp = listFromW[index]
    listFromW[index] = listFromW[minIndex]
    listFromW[minIndex] = temp
    
    for i in range(index+1, len(w)-1):
        maxVal = 0
        minIndex = -1
        for j in range(i+1, len(w)):
            if listFromW[j] < listFromW[i]:
                if minIndex == -1:
                    maxVal = ord(w[i]) - ord(w[j])
                    minIndex = j
                elif maxVal < ord(w[i]) - ord(w[j]):
                    maxVal = ord(w[i]) - ord(w[index])
                    minIndex = j
        if minIndex != -1:
            temp = listFromW[i]
            listFromW[i] = listFromW[minIndex]
            listFromW[minIndex] = temp
    
    return ''.join(listFromW)
    
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    T = int(input().strip())

    for T_itr in range(T):
        w = input()

        result = biggerIsGreater(w)

        fptr.write(result + '\n')

    fptr.close()
