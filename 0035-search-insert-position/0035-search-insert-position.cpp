class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();  // Default to the end if target is greater than all elements

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                ans = mid;  // Update ans to mid, as we found a candidate position
                high = mid - 1;  // Move left to check for earlier occurrences
            } else {
                low = mid + 1;  // Move right if nums[mid] < target
            }
        }
        
        return ans;
    }
};
