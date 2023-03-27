#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'extraLongFactorials' function below.
#
# The function accepts INTEGER n as parameter.
#

def extraLongFactorials(n):
    # Write your code here
    factorials = 1;
    for x in range(1, n + 1):
        factorials *= x;
    print(factorials)
    
if __name__ == '__main__':
    n = int(input().strip())

    extraLongFactorials(n)
