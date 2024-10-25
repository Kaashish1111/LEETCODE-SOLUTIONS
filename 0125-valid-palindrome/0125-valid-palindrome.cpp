#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Move left pointer forward if it's not an alphanumeric character
            while (left < right && !isalnum(s[left])) left++;
            // Move right pointer backward if it's not an alphanumeric character
            while (left < right && !isalnum(s[right])) right--;

            // Convert both characters to lowercase for case-insensitive comparison
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
