#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // charIndex stores the last seen position + 1 of each character
        // ASCII size 128 covers English letters, digits, and symbols
        vector<int> charIndex(128, 0);
        int n = s.length();
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            // If the character was seen before in the current window, 
            // move 'left' to the right of the previous occurrence
            left = max(left, charIndex[s[right]]);

            // Calculate current window size and update maxLength
            maxLength = max(maxLength, right - left + 1);

            // Store the next index (1-based) to avoid -1 initialization
            charIndex[s[right]] = right + 1;
        }

        return maxLength;
    }
};
