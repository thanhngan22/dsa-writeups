#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'separateNumbers' function below.
#
# The function accepts STRING s as parameter.
#

def separateNumbers(s):
    # Write your code here
    
    # init values
    
    if len(s) <= 1:
        print('NO')
        return
    value = []
    for lenS in range (1, int(len(s)/2 + 1)):
        if lenS >= 2 and s[0] == '0':
            print('NO')
            return
        firstNum = s[0:lenS]
        if len(value) >= 1:
            value.clear()
        value.append(firstNum)
        isBeautiful = True
        # print('\n')
        # print(f"first num: {value}")
        
        # start to check next numbers
        start = lenS
        numDigitOfNextNumber = len(str(int(firstNum) + 1))
        end = start + numDigitOfNextNumber
        i = 1
        while end <= len(s):
            nextNumber = s[start:end]
            if (int(nextNumber) - int(firstNum) != i) :
                isBeautiful = False
                break
            # update values
            i += 1
            start = end
            numDigitOfNextNumber = len(str(int(nextNumber) + 1))
            end = start + numDigitOfNextNumber
            # print(f"{nextNumber}", end = ', ')
            if start < len(s) and end > len(s):
                isBeautiful = False
                
        if isBeautiful :
            break
    if isBeautiful:
        print(f"YES {str(value[0])}")
    else:
        print('NO')
        
            
        
    
    

if __name__ == '__main__':
    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        separateNumbers(s)
