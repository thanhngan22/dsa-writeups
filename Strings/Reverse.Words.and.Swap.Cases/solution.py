#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'reverse_words_order_and_swap_cases' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING sentence as parameter.
#

def reverse_words_order_and_swap_cases(sentence):
    # Write your code here
    # get all words in sentences
    words = []
    startIndex = 0
    i = 0
    while i < len(sentence): 
        startIndex = i;
        # get this word
        endIndex = i + 1
        while endIndex < len(sentence) and sentence[endIndex] != ' ':
            endIndex += 1
        word = []
        word[startIndex:endIndex] = sentence[startIndex : endIndex]
        for k in range(len(word)):
            if word[k].isupper() :
                word[k] = word[k].lower()
            else :
                word[k] = word[k].upper()
        words.append(''.join(word))
        print(f"word: {word}")
        i = endIndex + 1
    reverse = []
    for j in range(len(words)-1, -1, -1):
        reverse.append(words[j])
    res = ' '.join(reverse)
    return res
                
            
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    sentence = input()

    result = reverse_words_order_and_swap_cases(sentence)

    fptr.write(result + '\n')

    fptr.close()
