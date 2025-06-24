class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int left = 0, right = n - 1;
        char ans = letters[0]; // Since the array is circular, letters[0] is the default

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (letters[mid] > target) {
                ans = letters[mid]; // possible answer found
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
