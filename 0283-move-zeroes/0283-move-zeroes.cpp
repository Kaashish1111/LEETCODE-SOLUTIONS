class Solution {public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);  // Use a vector instead of fixed-size array
        int index = 0;
        // Copy non-zero elements to temp array
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                temp[index] = nums[i];
                index++;
            }
        }
        // Fill remaining positions with zeros
        while (index < n) {
            temp[index] = 0;
            index++;
        }
        // Copy the temp array back to the original nums array
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
        // Now nums is modified as expected, you can print it
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

