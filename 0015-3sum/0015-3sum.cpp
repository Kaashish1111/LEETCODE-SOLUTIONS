// Brute Force
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         int n = nums.size();
        
//         // Sort the array to handle duplicates easily
//         sort(nums.begin(), nums.end());
        
//         for (int i = 0; i < n; i++) {
//             // Skip duplicate elements for the first number
//             if (i > 0 && nums[i] == nums[i - 1]) continue;
            
//             for (int j = i + 1; j < n; j++) {
//                 // Skip duplicates for the second number
//                 if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
//                 for (int k = j + 1; k < n; k++) {
//                     // Skip duplicates for the third number
//                     if (k > j + 1 && nums[k] == nums[k - 1]) continue;

//                     if (nums[i] + nums[j] + nums[k] == 0) {
//                         ans.push_back({nums[i], nums[j], nums[k]});
//                     }
//                 }
//             }
//         }
        
//         return ans;
//     }
// };

// best approch
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        // Sort the array to handle duplicates and allow two-pointer technique
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for `i`
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // Move `j` and `k` to the next unique values
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                } 
                else if (sum < 0) {
                    j++;
                } 
                else {
                    k--;
                }
            }
        }
        
        return ans;
    }
};