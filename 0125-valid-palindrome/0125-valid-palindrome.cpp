class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        
        // Convert to lowercase and filter out non-alphanumeric characters
        for (char c : s) {
            if (isalnum(c)) {          // Check if character is alphanumeric
                filtered += tolower(c); // Append lowercase alphanumeric character
            }
        }
        
        int l = filtered.length();
        for (int i = 0; i < l / 2; ++i) {
            if (filtered[i] != filtered[l - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};