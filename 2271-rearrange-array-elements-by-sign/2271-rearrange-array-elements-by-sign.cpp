class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives;
        vector<int> negatives;

        // Separate positive and negative numbers
        for (int num : nums) {
            if (num > 0) {
                positives.push_back(num);
            } else {
                negatives.push_back(num);
            }
        }

        vector<int> ans;
        // Interleave the positive and negative numbers
        for (int i = 0; i < positives.size(); i++) {
            ans.push_back(positives[i]);  // Add positive
            ans.push_back(negatives[i]);  // Add negative
        }

        return ans;
    }
};
