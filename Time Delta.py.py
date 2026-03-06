import math
import os
import random
import re
import sys
from datetime import datetime

# Complete the time_delta function below.
def time_delta(t1, t2):
    # Format: Day dd Mon yyyy hh:mm:ss +xxxx
    # Example: Sun 10 May 2015 13:54:36 -0700
    time_format = '%a %d %b %Y %H:%M:%S %z'
    
    # Convert strings to datetime objects
    dt1 = datetime.strptime(t1, time_format)
    dt2 = datetime.strptime(t2, time_format)
    
    # Calculate absolute difference in seconds
    # .total_seconds() returns a float, so we cast to int
    diff = int(abs((dt1 - dt2).total_seconds()))
    
    return str(diff)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        t1 = input()
        t2 = input()

        delta = time_delta(t1, t2)

        fptr.write(delta + '\n')

    fptr.close()
