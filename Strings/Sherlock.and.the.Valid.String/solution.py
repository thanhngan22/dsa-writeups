#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'isValid' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isValid_0(s):
    # Write your code here
    length = 0
    
    record_lst = [] #unique alphabet
    record_num = [] #each alphabet occur times
    for i in range(len(s)):
        if s[i] not in record_lst:
            record_lst.append(s[i])
            record_num.append(1)
            length += 1
        else:
            index = record_lst.index(s[i])
            record_num[index] += 1
    
    unique = []
    occur_min = 0 #count minimum occur times in each alphabet occur times
    occur_max = 0 #count maximum occur times in each alphabet occur times
    for i in record_num:
        if i == min(record_num):
            occur_min += 1
        if i == max(record_num):
            occur_max += 1
        if i not in unique: # unique occur times
            unique.append(i)
    
    print(unique)      
    print(record_lst) 
    print(record_num)
    
    # Every alphabet has same occur time is a valid string
    if len(unique) == 1:
        return "YES"  
    
    # Maximum only occur 1 time and the difference of maximum occur time and minumum occur time = 1, remove a alphabet that occur the most time can get a valid string     
    if occur_max == 1 and max(record_num) - min(record_num) == 1 and len(unique) == 2:
        return "YES"        
    
    # a string that consists of two alphabets, and one of the alphabet that only occur 1 time, remove it can get a valid string
    if occur_min == 1 and min(record_num) == 1 and len(unique) == 2:
        return "YES"
    
    #default: return invalid string
    return "NO"

    
def isValid_1(s):
    arr = [0] * 26
    print(arr)
    for i in s:
        arr[ord(i) - ord('a')] += 1

    print(arr)
    setCount = set(arr)
    setCount.discard(0)
    if len(setCount) == 1:
        return 'YES'
    if len(setCount) > 2:
        return 'NO'

    num1 = setCount.pop()
    num2 = setCount.pop()
    [count1, count2] = [0, 0]

    for x in arr:
        if num1 == x:
            count1 += 1
        elif num2 == x:
            count2 += 1
    
    if count1 == 1 and (num1 - num2 == 1 or num1 == 1):
        return 'YES'
    if count2 == 1 and (num2 - num1 == 1 or num2 == 1):
        return 'YES'
    
    return 'NO'

def isValid(s):
    # Write your code here
    if len(s) == 1 :
        return 'YES'
    
    array = []
    array[0:len(s)] = s[0:len(s)]
    count = []
    
    while len(array) > 0:
        c = array[0]
        array.pop(0)
        num = 1;
        k = 0
        
        while (k < len(array)):
            if array[k] == c:
                num += 1
                array.pop(k)
            else :
                k += 1
        count.append(num)
    
    # if len(s) == 1 or len(set(count)) == 1:
    #     return 'YES'
        
    # value = count[0]
    # removed = 0
    # k = 0
    # while k < len(count):
    #     if count[k] == value:
    #         count.pop(k)
    #         removed += 1
    #     else :
    #         k += 1



    # if len(count) == 0:
    #     return 'YES'
    # if len(count) == 1 and abs(count[0] - value) == 1:
    #     return 'YES'
    # if len(set(count)) == 1 and abs(count[0] - value) == 1 and removed == 1:
    #     return 'YES'
    # return 'NO'
    

    maxCount = 1
    startIndex = 0
    if len(count) >= 3:
        for i in range(1,3):
            if count[i] == count[0]:
                maxCount += 1
        if maxCount == 1:
            startIndex = 1
    value = count[startIndex]
    
    # numRemoved = 0
    # for i in range(0, len(count)):
    #     if abs(count[i] - value) > 1:
    #         return 'NO'
    #     if abs(count[i] - value) == 1:
    #         if numRemoved == 1:
    #             return 'NO'
    #         else :
    #             numRemoved = 1
    
    num_diff_counts = 0
    for i in range(len(count)):
        if count[i] != value:
            num_diff_counts += 1
            if num_diff_counts > 1:
                return 'NO'
            if count[i] != 1 and abs(count[i] - value) > 1:
                return 'NO'
            
            
    return 'YES'
    
    
    # k = 0
    # while k < len(count):
    #     if count[k] == value:
    #         count.pop(k)
    #     else :
    #         k += 1 
            
    # if len(count) == 0:
    #     return 'YES'
    
    # if len(count) == 1 and abs(count[0] - value) == 1:
    #     return 'YES'
    # return 'NO'
            
                
            
        
        
    
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
