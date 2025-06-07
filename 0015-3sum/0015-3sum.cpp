// brute force
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> s;
//         int n = nums.size();
//         sort(nums.begin(), nums.end()); // sort once

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 for (int k = j + 1; k < n; k++) {
//                     if (nums[i] + nums[j] + nums[k] == 0) {
//                         s.insert({nums[i], nums[j], nums[k]});
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(s.begin(),s.end());
//         return ans;
//     }
// };

// optimal approch
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> s;
//         int n = nums.size();
//         sort(nums.begin(), nums.end()); // Sort once for duplicate handling

//         for (int i = 0; i < n; i++) {
//             set<int> chotu;
//             for (int j = i + 1; j < n; j++) {
//                 int third = -(nums[i] + nums[j]);
//                 if (chotu.find(third) != chotu.end()) {
//                     vector<int> temp = {nums[i], nums[j], third};
//                     sort(temp.begin(), temp.end()); // ✅ sort the triplet
//                     only s.insert(temp);
//                 }
//                 chotu.insert(nums[j]);
//             }
//         }

//         vector<vector<int>> ans(s.begin(), s.end());
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;
        int n=arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            // remove duplicates:
            if (i != 0 && arr[i] == arr[i - 1])
                continue;

            // moving 2 pointers:
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // skip the duplicates:
                    while (j < k && arr[j] == arr[j - 1])
                        j++;
                    while (j < k && arr[k] == arr[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};