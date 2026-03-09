#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        // Mapping of digits to letters
        unordered_map<char, string> phone = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> result;
        string current;
        backtrack(0, digits, current, result, phone);
        return result;
    }

private:
    void backtrack(int index, const string& digits, string& current, 
                   vector<string>& result, unordered_map<char, string>& phone) {
        // Base case: If the combination is done
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get the letters that the current digit maps to
        string letters = phone[digits[index]];
        for (char letter : letters) {
            current.push_back(letter);           // Choose
            backtrack(index + 1, digits, current, result, phone); // Explore
            current.pop_back();                  // Un-choose (backtrack)
        }
    }
};
