class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0); // Create a vector with the same size and initialize with 0
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                arr[j] = nums[i];
                j++;
            }
        }

        // Copy the result back to the original vector
        for (int i = 0; i < n; i++) {
            nums[i] = arr[i];
        }
    }
};
