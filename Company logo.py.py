import math
import os
import random
import re
import sys
from collections import Counter

if __name__ == '__main__':
    s = input()
    
    
    counts = Counter(s)
    
    # 2. Sort the counts
    sorted_chars = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
    
    # 3. Print the top three
    for i in range(3):
        print(f"{sorted_chars[i][0]} {sorted_chars[i][1]}")
