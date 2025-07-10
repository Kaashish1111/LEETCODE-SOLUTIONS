// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> positives;
//         vector<int> negatives;

//         // Separate positive and negative numbers
//         for (int num : nums) {
//             if (num > 0) {
//                 positives.push_back(num);
//             } else {
//                 negatives.push_back(num);
//             }
//         }

//         // Fill nums with alternating positives and negatives
//         for(int i = 0; i < positives.size(); i++) {
//             nums[2 * i] = positives[i];       // Place positive numbers at even indices
//             nums[2 * i + 1] = negatives[i];    // Place negative numbers at odd indices
//         }

//         return nums;  // Return the rearranged array
//     }
// };

// better optimised 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int pos = 0, neg = 1;
        for (auto i : nums) {
            if (i > 0) {
                ans[pos] = i;
                pos += 2;
            } else {
                ans[neg] = i;
                neg += 2;
            }
        }
        return ans;
    }
};
