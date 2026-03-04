#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();
        // dp[i][j] will be true if s[0...i-1] matches p[0...j-1]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        dp[0][0] = true; // Empty string and empty pattern match

        // Initialize the first row for patterns like a*, a*b*, etc. that match an empty string
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                char sChar = s[i - 1];
                char pChar = p[j - 1];

                if (pChar == sChar || pChar == '.') {
                    // If the current characters match or pattern has '.', depend on the previous state
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pChar == '*') {
                    // '*' can match zero occurrences of the preceding element
                    dp[i][j] = dp[i][j - 2]; 

                    // Or it can match one or more occurrences if the preceding element matches the current string character
                    char pPrev = p[j - 2];
                    if (pPrev == sChar || pPrev == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // Use || to consider both possibilities
                    }
                }
            }
        }

        return dp[m][n]; // The final result is at the bottom-right corner
    }
};
