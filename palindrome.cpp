class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases:
        // 1. Negative numbers are not palindromes (e.g., -121)
        // 2. If the last digit is 0, the first digit must also be 0 (only '0' itself qualifies)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            // Take the last digit of x and add it to reversedHalf
            reversedHalf = reversedHalf * 10 + x % 10;
            // Remove the last digit from x
            x /= 10;
        }

        // When the length is odd, we can get rid of the middle digit by reversedHalf/10
        // For example, for 121, at the end of the loop x = 1, reversedHalf = 12
        // Since the middle digit doesn't matter in a palindrome, we use /10
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
