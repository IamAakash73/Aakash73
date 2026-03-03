def merge_the_tools(string, k):
    """
    Splits the string into substrings of length k, removes duplicate characters
    from each substring while preserving order, and prints the results.
    """
    # Iterate through the string in steps of k
    for i in range(0, len(string), k):
        # Extract the current substring
        substring = string[i:i + k]
        
        # Use a dictionary or a set to keep track of seen characters 
        # while preserving the original order of first appearance.
        seen_chars = {}
        result_subsequence = []
        
        for char in substring:
            if char not in seen_chars:
                result_subsequence.append(char)
                seen_chars[char] = True
                
        # Join the characters to form the final string for this part
        # and print it on a new line.
        print("".join(result_subsequence))

if __name__ == '__main__':
    # Sample Input handling as per problem description
    # string, k = input(), int(input())
    # merge_the_tools(string, k)

    # Example test with the sample input
    s = 'AABCAAADA'
    k = 3
    merge_the_tools(s, k)
