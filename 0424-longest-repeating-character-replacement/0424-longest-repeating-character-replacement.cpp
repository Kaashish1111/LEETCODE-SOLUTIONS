// brute force
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//          int n = s.length();
//     int maxLength = 0;

//     // Iterate over all possible substrings
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             // Create a frequency array for 26 characters
//             int freq[26] = {0};
//             int maxFreq = 0;

//             // Count the frequency of each character in the current substring
//             for (int l = i; l <= j; l++) {
//                 freq[s[l] - 'A']++;
//                 if (freq[s[l] - 'A'] > maxFreq) {
//                     maxFreq = freq[s[l] - 'A'];
//                 }
//             }

//             // Calculate the number of replacements needed
//             int replacements = (j - i + 1) - maxFreq;
//             if (replacements <= k) {
//                 maxLength = max(maxLength, j - i + 1);
//             }
//         }
//     }
//     return maxLength;
//     }
// };

class Solution {
public:
int characterReplacement(string s, int k) {
    int n = s.length();
    int maxLength = 0;
    int maxFreq = 0; // Tracks the frequency of the most common character in the window
    int freq[26] = {0}; // Array to store the frequency of characters in the window

    int left = 0; // Left pointer for the sliding window

    for (int right = 0; right < n; right++) {
        // Update the frequency of the current character
        freq[s[right] - 'A']++;
        // Update the max frequency of any character in the current window
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        // Check if the window is valid
        int windowSize = right - left + 1;
        if (windowSize - maxFreq > k) {
            // If more replacements are needed than allowed, shrink the window
            freq[s[left] - 'A']--;
            left++;
        }

        // Update the maximum length of a valid window
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}
};