#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'climbingLeaderboard' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY ranked
#  2. INTEGER_ARRAY player
#

def climbingLeaderboard1(ranked, player): #(time limit exceeded)
    # Write your code here\
    distinctRank = []
    [distinctRank.append(x) for x in ranked if x not in distinctRank]
    
    newRank = []
    print(f"distinct rank: {distinctRank}")
    
    for x in player:
        print(f"player: {x}")
        left = 0;
        right = len(distinctRank);
        mid = int ((left + right)/2)
        while 0 <= mid <= len(distinctRank):
            print(f"value: {distinctRank[mid]}, {mid}" )
            if distinctRank[mid] == x:
                newRank.append(mid + 1);
                break;
            if distinctRank[mid] > x and mid + 1 < len(distinctRank) and distinctRank[mid + 1] < x:
                newRank.append( mid + 2)
                break;
            if distinctRank[mid] < x and mid == 0:
                newRank.append(1);
                break;
            if distinctRank[mid] > x and mid == len(distinctRank) - 1:
                newRank.append(len(distinctRank) + 1)
                break;
            if distinctRank[mid] > x:
                left = mid + 1;
                mid = int((left + right) / 2);
            elif distinctRank[mid] < x:
                right = mid -1;
                mid = int((left + right)/2)
    return newRank
    
def climbingLeaderboard2(ranked, player) : #(time limit exceeded)
    distinctRank = []
    [distinctRank.append(x) for x in ranked if x not in distinctRank]
    
    newRank = []
    index = len(distinctRank) - 1
    
    for x in player:
        while index >= 0:
            if distinctRank[index] <= x and index == 0:
                newRank.append(1);
                if distinctRank[index] < x: distinctRank.append(x)
                break;
            if distinctRank[index] == x:
                newRank.append(index + 1);
                break;
            elif distinctRank[index] > x:
                newRank.append(index + 2);
                distinctRank.append(x);
                break;
            index -= 1;
        index = newRank[len(newRank) - 1] - 1;
    return newRank   
        
# def climbingLeaderboard(ranked, player) :
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ranked_count = int(input().strip())

    ranked = list(map(int, input().rstrip().split()))

    player_count = int(input().strip())

    player = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(ranked, player)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
