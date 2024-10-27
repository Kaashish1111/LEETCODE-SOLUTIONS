#include <string>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(std::string s) {
        // Convert to lowercase and remove non-alphanumeric characters
        s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); }), s.end());
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);

        int len = s.size();
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
