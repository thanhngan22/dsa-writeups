#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'strangeCounter' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts LONG_INTEGER t as parameter.
#

def strangeCounter(t):
    # Write your code here
    # solution:
    # timeInACycle = t * 2^(cycle-1)
    # startCycle = totalTime - time + 1
    # endCycle = totalTime for time of every cycle before
    
    # find the cycle that t belong to
    indexCycle = -1 # initial value index of cycle
    cycle = 1
    totalTime = 3
    while indexCycle == -1 :
        time = 3 * 2**(cycle - 1)
        start = totalTime - time + 1
        end = totalTime
        if start <= t <= end:
            indexCycle = cycle
            return time - (t - start)
        # update data
        totalTime += 2*time
        cycle += 1
    
    
    
                
        
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    result = strangeCounter(t)

    fptr.write(str(result) + '\n')

    fptr.close()
