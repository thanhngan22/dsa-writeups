#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'organizingContainers' function below.
#
# The function is expected to return a STRING.
# The function accepts 2D_INTEGER_ARRAY container as parameter.
#

# def organizingContainers(container):
#     # Write your code here
#     n = len(container)
#     for x in range(0, n):
#         totalValueRow = 0
#         for k in container[x] : totalValueRow += k
#         totalValueRow -= container[x][x];
        
#         totalValueCol = 0
#         for y in range(0,n):
#             totalValueCol += container[y][x] 
#         totalValueCol -= container[x][x]
#         print(f"value row {x} is : {totalValueRow} , value Col {x} is : {totalValueCol}\n")
#         if totalValueRow !=  totalValueCol:
#             return "Impossible"
#     return "Possible"
    
def organizingContainers(container):
    # Compute the total number of balls of each type and the total capacity of each container
    n = len(container)
    balls_of_type = [0] * n
    capacity_of_container = [0] * n
    for i in range(n):
        for j in range(n):
            balls_of_type[j] += container[i][j]
            capacity_of_container[i] += container[i][j]
    
    # Check if it is possible to sort the balls
    balls_of_type.sort()
    capacity_of_container.sort()
    if balls_of_type == capacity_of_container:
        return "Possible"
    else:
        return "Impossible"

    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        n = int(input().strip())

        container = []

        for _ in range(n):
            container.append(list(map(int, input().rstrip().split())))

        result = organizingContainers(container)

        fptr.write(result + '\n')

    fptr.close()
