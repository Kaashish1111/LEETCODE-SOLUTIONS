unordered_map<char, string> digitToLetters = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Base case — if input is empty
        if (digits.empty())
            return {};

        // Base case — if there is only one digit
        if (digits.size() == 1) {
            vector<string> base;
            string letters = digitToLetters[digits[0]];
            for (char c : letters)
                base.push_back(string(1, c));
            return base;
        }

        // Take first digit and rest of the string
        char ch = digits[0];
        string restof = digits.substr(1);

        // Recursive call for rest of the string
        vector<string> res = letterCombinations(restof);

        vector<string> finalres;

        // For every letter of current digit, and every string from recursion
        for (char letter : digitToLetters[ch]) {
            for (string s : res) {
                finalres.push_back(string(1, letter) + s);
            }
        }

        return finalres;
    }
};
