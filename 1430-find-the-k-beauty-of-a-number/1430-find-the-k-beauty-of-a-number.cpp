class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num); // Convert the number to string
        int count = 0;
        for (int i = 0; i <= s.length() - k; i++) {
            string sub = s.substr(i, k); // Get k-length substring
            int val = stoi(sub);         // Convert substring to int

            if (val != 0 && num % val == 0) {
                count++;
            }
        }
        return count;
    }
};
