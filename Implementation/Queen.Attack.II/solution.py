#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'queensAttack' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER k
#  3. INTEGER r_q
#  4. INTEGER c_q
#  5. 2D_INTEGER_ARRAY obstacles
#

def queensAttack(n, k, r_q, c_q, obstacles):
    # Initialize the number of squares attacked by the queen to zero
    count = 0

    # Create a set of obstacle positions for quick lookup
    obstacles = set([(r, c) for r, c in obstacles])

    # Define the possible moves for the queen
    directions = [
        (-1, 0),  # up
        (1, 0),  # down
        (0, -1),  # left
        (0, 1),  # right
        (-1, -1),  # up-left
        (-1, 1),  # up-right
        (1, -1),  # down-left
        (1, 1)  # down-right
    ]

    # Check each possible move for the queen
    for dr, dc in directions:
        r, c = r_q + dr, c_q + dc
        while 1 <= r <= n and 1 <= c <= n and (r, c) not in obstacles:
            # If the square is not an obstacle and is within the board, count it
            count += 1
            r += dr
            c += dc

    # Return the number of squares attacked by the queen
    return count


# def queensAttack(n, k, r_q, c_q, obstacles):
#     # Write your code here
    
#     # init matrix
#     matrix = [[1 for j in range(n + 1) ] for i in range(n + 1) ]
    
#     # queen : 2
#     # obstacles: 0
#     # others: 1
#     matrix[r_q][c_q] = 2;
    
#     for i in range(k):
#         x = obstacles[i][0];
#         y = obstacles[i][1];
#         matrix[x][y] = 0
    
#     count = 0;
    
#     # count in the row
#     # left
#     i = c_q - 1;
#     while 1:
#         if i <= 0 or matrix[r_q][i] == 0:
#             break;
#         i -= 1;
#         count += 1;
    
#     # right
#     i = c_q + 1;
#     while 1:
#         if i > n or matrix[r_q][i] == 0:
#             break;
#         i += 1;
#         count += 1;
    
#     # count in the col
#     # up
#     i = r_q - 1;
#     while 1:
#         if i <= 0 or matrix[i][c_q] == 0:
#             break;
#         i -= 1;
#         count += 1
    
#     # down
#     i = r_q + 1
#     while 1:
#         if i > n or matrix[i][c_q] == 0:
#             break;
#         i += 1;
#         count += 1;
    
#     # left upper cross
#     i = r_q - 1;
#     j = c_q - 1;
#     while 1:
#         if i <= 0 or j <= 0 or matrix[i][j] == 0:
#             break;
        
#         i -= 1
#         j -= 1;
#         count += 1
        
#     # right upper cross
#     i = r_q - 1;
#     j = c_q + 1;
#     while 1:
#         if i <= 0 or j > n or matrix[i][j] == 0:
#             break;
        
#         i -= 1;
#         j += 1;
#         count += 1
        
#     # left bottom cross
#     i = r_q + 1;
#     j = c_q - 1;
#     while 1:
#         if i > n or j <= 0 or matrix[i][j] == 0:
#             break;
        
#         i += 1;
#         j -= 1;
#         count += 1
        
#     # right bottom cross
#     i = r_q + 1;
#     j = c_q + 1;
#     while 1:
#         if i > n or j > n or matrix[i][j] == 0:
#             break;
        
#         i += 1
#         j += 1
#         count += 1
        
#     return count;
        
 

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    second_multiple_input = input().rstrip().split()

    r_q = int(second_multiple_input[0])

    c_q = int(second_multiple_input[1])

    obstacles = []

    for _ in range(k):
        obstacles.append(list(map(int, input().rstrip().split())))

    result = queensAttack(n, k, r_q, c_q, obstacles)

    fptr.write(str(result) + '\n')

    fptr.close()
