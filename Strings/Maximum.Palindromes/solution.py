#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'initialize' function below.
#
# The function accepts STRING s as parameter.
#
def mod_inverse(a, m = 10**9 + 7):
    """
    Returns the modular inverse of `a` with respect to the modulus `m`.
    """
    # Calculate gcd(a, m) using the Extended Euclidean Algorithm
    gcd, x, y = extended_gcd(a, m)
    
    # If gcd(a, m) != 1, then modular inverse doesn't exist
    if gcd != 1:
        return None
    
    # Otherwise, return the modular inverse of `a` with respect to `m`
    return x % m

def extended_gcd(a, b):
    """
    Returns a tuple (gcd, x, y) where `gcd` is the greatest common divisor of
    a and b, and `x` and `y` are integers such that ax + by = gcd(a, b).
    """
    # Base case
    if a == 0:
        return (b, 0, 1)
    
    # Recursive case
    gcd, x1, y1 = extended_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    
    return (gcd, x, y)

def initialize(s):
    temp = [0]*26
    for x in s:
        myList.append(temp.copy())
        temp[ord(x) - ord('a')] += 1

    myList.append(temp.copy())
    n = len(s) + 1

    for i in range(1, n):
        list_fac[i] = list_fac[i - 1] * i % MOD
        list_fac_inv[i] = list_fac_inv[i - 1] * mod_inverse(i) % MOD
def answerQuery(l, r):
    # Return the answer for this query modulo 1000000007.
    arr = [0] * 26
    for i in range(len(arr)):
        arr[i] = myList[r][i] - myList[l - 1][i]
    
    print(arr)
    arrEven = []
    countOdd = 0
    for x in arr:
        if x != 0:
            if x % 2 == 0:
                arrEven.append(x // 2)
            else:
                countOdd += 1
                if x > 1:
                    arrEven.append((x - 1) // 2)

    res = list_fac[sum(arrEven)]

    for x in arrEven:
        res %= MOD
        res *= list_fac_inv[x]

    return res * max(1, countOdd) % MOD

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = len(s) + 1
    MOD = 10**9 + 7
    myList = []
    list_fac = [1] * n
    list_fac_inv = [1]*n
    initialize(s)
    
    q = int(input().strip())

    for q_itr in range(q):
        first_multiple_input = input().rstrip().split()

        l = int(first_multiple_input[0])

        r = int(first_multiple_input[1])

        result = answerQuery(l, r)

        fptr.write(str(result) + '\n')

    fptr.close()
