def is_palindrome(n):
    number=str(n)
    if(number==number[::-1]):
        return True
def can(st) : 
    NO_OF_CHARS = 256
    # Create a count array and initialize   
    # all values as 0 
    count = [0] * (NO_OF_CHARS) 
  
    # For each character in input strings, 
    # increment count in the corresponding 
    # count array 
    for i in range( 0, len(st)) : 
        count[ord(st[i])] = count[ord(st[i])] + 1
  
    # Count odd occurring characters 
    odd = 0
      
    for i in range(0, NO_OF_CHARS ) : 
        if (count[i] & 1) : 
            odd = odd + 1
  
        if (odd > 1) : 
            return False
              
    # Return true if odd count is 0 or 1,  
    return True
import itertools #https://docs.python.org/3/library/collections.html
import collections #https://docs.python.org/3/library/itertools.html
import random
import datetime
import sys
#import sklearn
#import pandas as pd
#import numpy as np
#import matplotlib.pyplot as plt
#https://docs.python.org/3/library/functions.html
t = int(input().strip())
for i in range(t):
    x = input().strip()
    letters, questions = x.split()
    total = 0
    y = input().strip()
    for _ in range(int(questions)):
        z = input().strip()
        start, end = z.split()
        temp = y[int(start)-1:int(end)]
        #print(temp)
        if is_palindrome(temp) == True:
            total += 1
            #print("A")
        else:
            if can(temp) == True:
                total += 1
                #print("B")

    print("Case #{}: {}".format(i+1, total))