class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int maxElement = INT_MIN;

        // Step 1: Find the maximum element
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxElement) {
                maxElement = nums[i];
            }
        }

        // Step 2: Create frequency array of size maxElement + 1
        vector<int> frequency(maxElement + 1, 0);

        // Step 3: Count frequency of each element
        for (int i = 0; i < n; i++) {
            frequency[nums[i]]++;
        }

        // Step 4: Store duplicates in result
        vector<int> result;
        for (int i = 0; i <= maxElement; i++) {
            if (frequency[i] > 1) {
                result.push_back(i);
            }
        }

        return result;
    }
};