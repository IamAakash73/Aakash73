import re
import sys

def solve():
    # Read the number of lines
    try:
        n = int(sys.stdin.readline())
    except ValueError:
        return

    for _ in range(n):
        line = sys.stdin.readline()
        # Use a regex to match ' && ' and ' || ' (note the leading and trailing spaces in the pattern)
        # The replacement string includes the spaces to maintain the original formatting.
        line = re.sub(r" (&&) ", r" and ", line)
        line = re.sub(r" (\|\|) ", r" or ", line)
        sys.stdout.write(line)

if __name__ == "__main__":
    solve()
