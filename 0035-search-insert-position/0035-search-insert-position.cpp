class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1, index = n;
        while (start <= end) {
            int mid = start + (end - start) / 2;  // Corrected midpoint calculation
            if (nums[mid] == target) {
                index = mid;
                break;
            } 
            else if (nums[mid] > target) {
                end = mid - 1;
                index = mid;
            } 
            else {
                start = mid + 1;
            }
        }
        return index;
    }
};
