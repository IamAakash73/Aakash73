import re

# Read dimensions
n, m = map(int, input().split())

# Read the matrix rows
matrix = [input() for _ in range(n)]

# 1. Transpose the matrix to read column by column
# 2. Join all characters into a single decoded string
decoded_string = "".join(["".join(column) for column in zip(*matrix)])

# 3. Use regex to replace symbols/spaces between alphanumeric characters
# Pattern: (?<=\w)\W+(?=\w)
# - (?<=\w): Positive lookbehind for an alphanumeric character
# - \W+: Matches one or more non-alphanumeric characters
# - (?=\w): Positive lookahead for an alphanumeric character
final_output = re.sub(r'(?<=\w)([^\w]+)(?=\w)', ' ', decoded_string)

print(final_output)
