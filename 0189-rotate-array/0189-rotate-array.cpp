class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // If k is greater than n, only k % n shifts are needed
        k = k % n;

        // Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the remaining n-k elements
        reverse(nums.begin() + k, nums.end());

        // Print the rotated array (optional)
        for (int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
    }
};
