#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'acmTeam' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts STRING_ARRAY topic as parameter.
#

def acmTeam(topic):
    # Write your code here
    numTeam = len(topic)     # number of attendees
    numTopic = len(topic[0])    # number of topic
    maxTopic = 0
    countTeam = 0
    
    for index, firstTeam in enumerate(topic[0:numTeam - 1]):
        for secondTeam in topic[index + 1 : numTeam ]:            
            # first solution : runtime err in some case
            # for i in range(0,numTopic):
            #     if (firstTeam[i] == '1' or secondTeam[i] == '1'):
            #         countTopic += 1
            
            # second solution
            resultInt = int(firstTeam, 2) | int(secondTeam, 2);
            countTopic = bin(resultInt).count('1')
            
            # print(f"count: {countTopic}, team1: {firstTeam}, team2: {secondTeam}\n")            
            if (countTopic > maxTopic):
                maxTopic = countTopic
                countTeam = 1
                continue
            if (countTopic == maxTopic):
                countTeam += 1
    res = [maxTopic, countTeam]
    return res
                    
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    topic = []

    for _ in range(n):
        topic_item = input()
        topic.append(topic_item)

    result = acmTeam(topic)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
