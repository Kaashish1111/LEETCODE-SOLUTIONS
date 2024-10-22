#include <string>
#include <sstream>  // For stringstream
#include <cctype>   // For toupper() and tolower()

class Solution {
public:
    std::string capitalizeTitle(std::string title) {
        std::stringstream ss(title);
        std::string word, result;
        
        while (ss >> word) {
            int len = word.length();
            
            // If the word length is 1 or 2, convert the whole word to lowercase
            if (len <= 2) {
                for (char &ch : word) {
                    ch = tolower(ch);
                }
            }
            // If the word length is greater than 2, capitalize the first letter and lowercase the rest
            else {
                word[0] = toupper(word[0]);
                for (int i = 1; i < len; i++) {
                    word[i] = tolower(word[i]);
                }
            }
            
            // Add the word to the result, followed by a space
            if (!result.empty()) {
                result += " ";
            }
            result += word;
        }
        
        return result;
    }
};
