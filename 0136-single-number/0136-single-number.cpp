class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Loop through each element in the array
        for(int i = 0; i < n; i++) {
            int count = 0; // Reset count for each element
            
            // Count how many times nums[i] appears in the array
            for(int j = 0; j < n; j++) {
                if(nums[j] == nums[i]) {
                    count++;
                }
            }
            
            // If count is 1, return the element that appears once
            if(count == 1) {
                return nums[i];
            }
        }
        
        return -1; // Return -1 if no single occurrence found (just for safety)
    }
};
