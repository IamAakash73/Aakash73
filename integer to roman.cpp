#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // Define value-symbol pairs in descending order
        // Including the subtractive forms (IV, IX, etc.) simplifies the logic
        const vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };
        
        string result = "";
        
        for (const auto& [value, symbol] : romanMap) {
            // While the current value can be subtracted from num
            while (num >= value) {
                result += symbol;
                num -= value;
            }
            // Optimization: if num hits 0, we can stop early
            if (num == 0) break;
        }
        
        return result;
    }
};
