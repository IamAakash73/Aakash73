#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // If there's only one row or the string length is less than numRows, 
        // the string is already in the correct "zigzag" pattern.
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        // Create a vector of strings to hold characters for each row.
        // The size is numRows because that's how many rows we need to fill.
        std::vector<std::string> rows(numRows, "");
        int currentRow = 0;
        bool goingDown = false;

        // Iterate through each character in the input string.
        for (char c : s) {
            // Append the current character to the appropriate row.
            rows[currentRow] += c;

            // If we're at the top or bottom row, we need to change direction.
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown; // Toggle direction
            }

            // Move to the next row based on the current direction.
            if (goingDown) {
                currentRow++;
            } else {
                currentRow--;
            }
        }

        // Concatenate all rows to get the final result string.
        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};

