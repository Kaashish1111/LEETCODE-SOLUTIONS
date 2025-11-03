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
        // if (digits.empty())
            // return {};
        if (digits.size() == 1) {
            vector<string> base;
            string letters = digitToLetters[digits[0]];
            for (char c : letters)
                base.push_back(string(1, c));
            return base;
        }
        char ch = digits[0];
        string restof = digits.substr(1);
        vector<string> res = letterCombinations(restof);
        vector<string> finalres;
        for (char letter : digitToLetters[ch]) {
            for (string s : res) {
                finalres.push_back(string(1, letter) + s);
            }
        }
        return finalres;
    }
};
